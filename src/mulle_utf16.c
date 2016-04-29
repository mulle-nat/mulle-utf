//
//  mulle_utf16.c
//  mulle-utf
//
//  Copyright (C) 2011 Nat!, Mulle kybernetiK.
//  All rights reserved.
//
//  Coded by Nat!
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are met:
//
//  Redistributions of source code must retain the above copyright notice, this
//  list of conditions and the following disclaimer.
//
//  Redistributions in binary form must reproduce the above copyright notice,
//  this list of conditions and the following disclaimer in the documentation
//  and/or other materials provided with the distribution.
//
//  Neither the name of Mulle kybernetiK nor the names of its contributors
//  may be used to endorse or promote products derived from this software
//  without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
//  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
//  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
//  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//  POSSIBILITY OF SUCH DAMAGE.
//

#include "mulle_utf16.h"

#include <errno.h>
#include <string.h>


#define FORBID_NON_CHARACTERS  1


static inline int   mulle_utf16_is_ascii_char( mulle_utf16_t c)
{
   return( c < 0x80);
}


int  mulle_utf16_is_valid_surrogatepair( mulle_utf16_t hi, mulle_utf16_t lo)
{
// invalid surrogate pairs
//   
//   D83F DFF* 
//   D87F DFF* 	
//   D8BF DFF* 	
//   D8FF DFF* 	
//   D93F DFF* 	
//   D97F DFF* 	
//   
//   ...
//   DBBF DFF* 	
//   DBFF DFF* 	
//   * = E or F

   if( lo == 0xDFFE || lo == 0xDFFF)
      switch( hi & 0xFF)
      {
      case 0x3F :
      case 0x7F :
      case 0xBF :
      case 0xFF :
      return( 0);
   }
   return( 1);
}


// bytebuffer code needs to be reintroduced sometime

//
// this also does not do any error checking, the UTF8 string must be perfect
//
// -1  dst buffer too small
//  0  OK!
//



// must be proper UTF16 code!
int  _mulle_utf16_convert_to_utf8_bytebuffer( void *buffer,
                                              void *(*advance)( void *, size_t),
                                              mulle_utf16_t *src,
                                              size_t len)
{
   mulle_utf16_t       *sentinel;
   unsigned char   *s;
   mulle_utf32_t       x;
   
   assert( src);
   
   if( len == (size_t) -1)
      len = mulle_utf16_strlen( src);
   if( ! len)
      return( 0);
             
   // if dst_len == -1, then sentinel - 1 = dst_sentinel (OK!)
   
   sentinel  = &src[ len];
   
   if( mulle_utf16_is_bom_char( *src))
      src += 1;
   
   while( src < sentinel)
   {
      x = *src++;
      if( x >= 0xD800 && x < 0xDC00)  // hi surrogate
      {
         // decode surrogate
         if( src >= sentinel)
         {
            errno = EFAULT;
            return( -1);
         }
         x = mulle_utf16_decode_surrogatepair( (mulle_utf16_t) x, *src++);
      }
      
      // 4 cases
      // < 0x80, < 0x800 < 0x10000, > 0x10000
      if( x < 0x800)
      {
         if( x < 0x80)
         {
            if( ! (s = (*advance)( buffer, 1)))
               return( -1);
            
            s[ 0] = (mulle_utf8_t) x;
            continue;
         }

         if( ! (s = (*advance)( buffer, 2)))
            return( -1);
         
         s[ 0] = 0xC0 | (mulle_utf8_t) (x >> 6);
         s[ 1] = 0x80 | (x & 0x3F);
         continue;
      }
      else
      {
         if( x < 0x10000)
         {
            assert( x >= 0xD800 || x < 0xE000);

            if( ! (s = (*advance)( buffer, 3)))
               return( -1);
         
            s[ 0] = 0xE0 | (mulle_utf8_t) (x >> 12);
            s[ 1] = 0x80 | ((x >> 6) & 0x3F);
            s[ 2] = 0x80 | (x & 0x3F);
            continue;
         }

         assert( x <= 0x10FFFF);
         
         if( ! (s = (*advance)( buffer, 4)))
            return( -1);
         
         s[ 0] = 0xF0 | (mulle_utf8_t) (x >> 18);
         s[ 1] = 0x80 | ((x >> 12) & 0x3F);
         s[ 2] = 0x80 | ((x >> 6) & 0x3F);
         s[ 3] = 0x80 | (x & 0x3F);
      }
   }
   return( 0);
}


int  _mulle_utf16_convert_to_utf32_bytebuffer( void *buffer,
                                               void *(*adduint32)( void *, uint32_t),
                                               mulle_utf16_t *src,
                                               size_t len)
{
   mulle_utf16_t   *sentinel;
   mulle_utf32_t   x;
   
   assert( src);
   
   if( len == (size_t) -1)
      len = mulle_utf16_strlen( src);
   if( ! len)
      return( 0);
   
   // if dst_len == -1, then sentinel - 1 = dst_sentinel (OK!)
   
   sentinel  = &src[ len];
   
   if( mulle_utf16_is_bom_char( *src))
      src += 1;
   
   while( src < sentinel)
   {
      x = *src++;
      if( x >= 0xD800 && x < 0xDC00)  // hi surrogate
      {
         // decode surrogate
         if( src >= sentinel)
         {
            errno = EFAULT;
            return( -1);
         }
         x = mulle_utf16_decode_surrogatepair( (mulle_utf16_t) x, *src++);
      }
      
      (*adduint32)( buffer, x);
   }
   return( 0);
}


//
// just checks that the surrogate pairs are ok
//
mulle_utf16_t  *mulle_utf16_validate( mulle_utf16_t *src, size_t len)
{
   mulle_utf16_t   c;
   mulle_utf16_t   d;
   mulle_utf16_t   *sentinel;
   
   assert( src);
   
   if( len == (size_t) -1)
      len = mulle_utf16_strlen( src);
   if( ! len)
      return( 0);
   
   sentinel = &src[ len];
   
   if( mulle_utf16_is_bom_char( *src))
      src += 1;
   
   for( ; src < sentinel; src++)
   {
      c = *src;

      // non characters, do not want
#if FORBID_NON_CHARACTERS
      if( c >= 0xFFFE || c >= 0xFDD0 && c <= 0xFDEF)
         return( src);
#endif      
      if( c < 0xD800 || c >= 0xE000)
         continue;
      
      if( c >= 0xDC00)
         return( src);
      if( src >= sentinel)
         return( src);
      d = *++src;
      if( d < 0xDC00 || d >= 0xE000)
         return( src);
      if( ! mulle_utf16_is_valid_surrogatepair( c, d))
         return( src - 1);
   }
   return( 0);
}

//
// this routine does not validate...
//
size_t  mulle_utf16_length_as_utf8( mulle_utf16_t *src, size_t len)
{
   mulle_utf16_t   c;
   mulle_utf16_t   *sentinel;
   
   assert( src);
   
   if( len == (size_t) -1)
      len = mulle_utf16_strlen( src);
   if( ! len)
      return( 0);
   
   sentinel = &src[ len];
   
   if( mulle_utf16_is_bom_char( *src))
   {
      src += 1;
      len -= 1;
   }
   
  
   for( ; src < sentinel;)
   {
      c = *src++;
      
      if( c < 0x80)
         continue;
         
      if( c < 0x0800)
      {
         len++;
         continue;
      }

      // not a surrogate pair ?
      if( c < 0xD800 || c > 0xE000)
      {
         len += 2;
         continue;
      }
      
      if( ++src > sentinel)
         return( -1);
         
      len += -1 + 3;
   }
   return( len);
}


size_t  mulle_utf16_strlen( mulle_utf16_t *src)
{
   size_t   len;

   len = 0;
   if( src)
      for( len = 0; *src++; len++);
   return( len);
}


size_t  mulle_utf16_strnlen( mulle_utf16_t *src, size_t len)
{
   mulle_utf16_t   *sentinel;
   
   sentinel = &src[ len];
   len = 0;
   while( src < sentinel)
   {
      if( ! *src)
         break;
      ++len;
   }
   return( len);
}


size_t  mulle_utf16_length( mulle_utf16_t *src, size_t len)
{
   mulle_utf16_t   c;
   mulle_utf16_t   *sentinel;
   size_t    dst_len;
   
   assert( src);
   assert( sizeof( wchar_t) == sizeof( mulle_utf16_t));
   
   if( len == (size_t) -1)
      len = mulle_utf16_strlen( src);
   if( ! len)
      return( 0);
   
   if( mulle_utf16_is_bom_char( *src))
   {
      src += 1;
      len -= 1;
   }
   
   sentinel = &src[ len];
   dst_len  = len;
   
   for( ; src < sentinel;)
   {
      c = *src++;
      
      if( c < 0x0800)
         continue;

      // not a surrogate pair ?
      if( c < 0xD800 || c > 0xE000)
      {
         dst_len--;
         continue;
      }
      
      if( ++src > sentinel)
         return( -1);
         
      dst_len -= 2;      
   }

   return( dst_len);
}


//
// make it more optimal, by (a) checking that pointer can be accessed with
// a long or long long
// (b) masking value with 0x80808080 to figure out if all are "ASCII"
//
int  mulle_utf16_information( mulle_utf16_t *src, size_t len, struct mulle_utf16_information *info)
{
   mulle_utf16_t                        _c;
   mulle_utf16_t                        *sentinel;
   struct mulle_utf16_information   dummy;
   
   if( ! info)
      info = &dummy;

   if( ! src)
      goto fail;

   //
   // remove leading BOM
   //
   info->has_bom = mulle_utf16_is_bom_char( *src);
   if( info->has_bom)
   {
      src += 1;
      len -= 1;
   }

   info->has_terminating_zero = 0;
   info->invalid_utf16        = NULL;
   info->start                = src;
   info->is_ascii             = 1;
   info->utf8len              =
   info->utf32len             =
   info->utf16len             = len;

   sentinel = &src[ len];
   
   for( ; src < sentinel; src++)
   {
      if( ! (_c = *src))
      {  
         info->has_terminating_zero = 1;
         break;
      }
      
      if( mulle_utf16_is_ascii_char( _c))
         continue;
      
      info->is_ascii = 0;
      info->utf8len++;

      if( _c >= 0x0800)
         info->utf8len++;
      
      // surrogate pair
      if( _c >= 0xD800 && _c <= 0xE000)
      {
         info->utf8len++;
         info->utf32len--;
         
         if( ++src >= sentinel)
            goto fail;
      }
      
#if FORBID_NON_CHARACTERS
      if( _c >= 0xFFFE || _c >= 0xFDD0 && _c <= 0xFDEF)
         goto fail;
#endif
   }

   return( 0);

fail:
   memset( info, 0, sizeof( *info));
   info->invalid_utf16 = src;
   return( -1);
}


int   mulle_utf16_is_ascii( mulle_utf16_t *src, size_t len)
{
   mulle_utf16_t   _c;
   mulle_utf16_t   *sentinel;
   
   assert( src);
   
   if( len == (size_t) -1)
      len = mulle_utf16_strlen( src);
   
   if( ! len)
      return( 1);
      
   if( mulle_utf16_is_bom_char( *src))
   {
      src += 1;
      len -= 1;
   }
   
   sentinel = &src[ len];
   
   while( src < sentinel)
   {
      _c = *src++;
      if( _c >= 0x80)
         return( 0);
   }

   return( 1);
}
