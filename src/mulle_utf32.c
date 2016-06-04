//
//  mulle_utf32.c
//  mulle-utf
//
//  Created by Nat! on 19.03.16.
//  Copyright © 2016 Mulle kybernetiK. All rights reserved.
//

#include "mulle_utf32.h"

#include "mulle_utf32_string.h"
#include "mulle_utf16.h"
#include "mulle_char5.h"
#include <assert.h>
#include <string.h>


#define FORBID_NON_CHARACTERS  1


static inline int   mulle_utf32_is_char5_char( mulle_utf32_t c)
{
   return( mulle_char5_encode( c) >= 0);
}


static inline int   mulle_utf32_is_ascii_char( mulle_utf32_t c)
{
   return( c < 0x80);
}


void  mulle_utf32_encode_as_surrogatepair_into_utf16_bytebuffer(
            void *buffer,
            void (*addbytes)( void *buffer, void *bytes, size_t size),
            mulle_utf32_t x)
{
   uint16_t  top;
   uint16_t  bottom;
   uint16_t  hi;
   uint16_t  lo;
   
   assert( x >= 0x10000 && x <= 0x10FFFF);
   
   x -= 0x10000;
   
   assert( (x >> 10) <= 0x3FF);
   
   top    = (uint16_t) (x >> 10);
   bottom = (uint16_t) (x & 0x3FF);
   
   hi = 0xD800 + top;
   lo = 0xDC00 + bottom;

   assert( hi >= 0xD800 && hi < 0xDC00);
   assert( lo >= 0xDC00 && lo < 0xE000);

   // (nat) I used to flip those adds around based on endianness, but I think
   // that was wrong
   (*addbytes)( buffer, &hi, sizeof( uint16_t));
   (*addbytes)( buffer, &lo, sizeof( uint16_t));
}


// must be proper UTF32 code!
size_t   mulle_utf32_length_as_utf8( mulle_utf32_t *src,
                                     size_t len)
{
   mulle_utf32_t       *sentinel;
   mulle_utf32_t       x;
   
   if( ! src)
      return( 0);
   
   if( len == (size_t) -1)
      len = mulle_utf32_strlen( src);
   if( ! len)
      return( 0);
             
   // if dst_len == -1, then sentinel - 1 = dst_sentinel (OK!)
   
   sentinel = &src[ len];
   
   while( src < sentinel)
   {
      x = *src++;
      
      if( x < 0x800)
      {
         if( x < 0x80)
            continue;

         ++len;
         continue;
      }

      if( x < 0x10000)
      {
         assert( ! mulle_utf_is_surrogate( x));
         len += 2;
         continue;
      }
      
      assert( x <= 0x10FFFF);
      len += 3;
   }
   return( len);
}


int   mulle_utf32_information( mulle_utf32_t *src, size_t len, struct mulle_utf_information *info)
{
   mulle_utf32_t                  _c;
   mulle_utf32_t                  *start;
   mulle_utf32_t                  *sentinel;
   struct mulle_utf_information   dummy;
   
   if( ! info)
      info = &dummy;

   info->has_terminating_zero = 0;
   info->invalid              = NULL;
   info->start                = src;
   info->is_ascii             = 1;
   info->is_char5             = 1;
   info->is_utf15             = 1;
   info->utf8len              = 0;
   info->utf16len             = 0;
   info->utf32len             = 0;
   info->has_bom              = 0;
   
   if( ! len)
      return( 0);
   if( len == (size_t) -1)
      len = mulle_utf32_strlen( src);
   
   //
   // remove leading BOM
   //
   info->has_bom = mulle_utf32_is_bom_char( *src);
   if( info->has_bom)
   {
      src += 1;
      len -= 1;
   }

   info->start = src;
   start       = src;
   sentinel    = &src[ len];
   
   for( ; src < sentinel; src++)
   {
      if( ! (_c = *src))
      {  
         info->has_terminating_zero = 1;
         break;
      }
      
      if( mulle_utf32_is_ascii_char( _c))
      {
         if( info->is_char5 && ! mulle_utf32_is_char5_char( _c))
            info->is_char5 = 0;
         continue;
      }
      
      info->is_ascii = 0;
      info->utf8len++;

      if( _c >= 0x0800)
         info->utf8len++;

      
#if FORBID_NON_CHARACTERS
      if( mulle_utf32_is_invalid_char( _c))
         goto fail;
#endif

      if( _c >= 0x8000)
         info->is_utf15 = 0;
      
      if( _c >= 0x10000)
      {
         info->utf8len++;
         info->utf16len++;
      }
   }

   info->utf8len  += src - start;
   info->utf16len += src - start;
   info->utf32len += src - start;
   info->is_char5 &= info->is_ascii;

   return( 0);

fail:
   memset( info, 0, sizeof( *info));
   info->invalid = src;
   return( -1);
}


// must be proper UTF32 code!
int  mulle_utf32_convert_to_utf8_bytebuffer( mulle_utf32_t *src,
                                             size_t len,
                                             void *buffer,
                                             void (*addbytes)( void *, void *, size_t size))
{
   mulle_utf32_t   *sentinel;
   mulle_utf32_t   x;
   mulle_utf8_t    s[ 4];
   
   if( len == (size_t) -1)
      len = mulle_utf32_strlen( src);
   if( ! len)
      return( 0);
             
   // if dst_len == -1, then sentinel - 1 = dst_sentinel (OK!)
   
   sentinel = &src[ len];
   
   while( src < sentinel)
   {
      x = *src++;
      
      if( x < 0x800)
      {
         if( x < 0x80)
         {
            s[ 0] = (mulle_utf8_t) x;
            (*addbytes)( buffer, s, 1);
            continue;
         }

         s[ 0] = 0xC0 | (mulle_utf8_t) (x >> 6);
         s[ 1] = 0x80 | (x & 0x3F);
         (*addbytes)( buffer, s, 2);
         continue;
      }
      else
      {
         if( x < 0x10000)
         {
            assert( ! mulle_utf_is_surrogate( x));

            s[ 0] = 0xE0 | (mulle_utf8_t) (x >> 12);
            s[ 1] = 0x80 | ((x >> 6) & 0x3F);
            s[ 2] = 0x80 | (x & 0x3F);
            (*addbytes)( buffer, s, 3);
            continue;
         }

         assert( x <= 0x10FFFF);
         
         s[ 0] = 0xF0 | (mulle_utf8_t) (x >> 18);
         s[ 1] = 0x80 | ((x >> 12) & 0x3F);
         s[ 2] = 0x80 | ((x >> 6) & 0x3F);
         s[ 3] = 0x80 | (x & 0x3F);
         (*addbytes)( buffer, s, 4);
      }
   }
   return( 0);
}



int  mulle_utf32_convert_to_utf16_bytebuffer( mulle_utf32_t *src,
                                              size_t len,
                                              void *buffer,
                                              void (*addbytes)( void *, void *, size_t size))
{
   mulle_utf32_t   *sentinel;
   mulle_utf32_t   x;
   mulle_utf16_t   _w;
   
   if( len == (size_t) -1)
      len = mulle_utf32_strlen( src);
   if( ! len)
      return( 0);
   
   // if dst_len == -1, then sentinel - 1 = dst_sentinel (OK!)
   
   sentinel = &src[ len];
   
   while( src < sentinel)
   {
      x = *src++;
      
      if( x < 0x10000)
      {
         assert( ! mulle_utf_is_surrogate( x));
         
         _w = (uint16_t) x;
         (*addbytes)( buffer, &_w, sizeof( _w));
         continue;
      }
      mulle_utf32_encode_as_surrogatepair_into_utf16_bytebuffer( buffer, addbytes, x);
   }
   return( 0);
}



