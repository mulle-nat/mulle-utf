//
//  mulle_utf8.h 
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
#ifndef mulle_utf8_h__
#define mulle_utf8_h__

#include "mulle_utf_type.h"

#include <string.h>


struct mulle_bytebuffer;

// Check: http://tools.ietf.org/html/rfc3629
// General considerations.
//    On the initial procurement of your UTF8 string, you must validate it once
//    then remember it as validated and don't change it (NSString :))
//    If this is the case, you can run all the other routines "quickly" without
//    having to validate again.
//
// These routines will strip off a leading BOM, but they will never add one.
//

//
// -2  UTF8 string malformed
// -1  dst buffer too small
//  0  OK!
//
size_t  mulle_utf8_convert_to_utf16( mulle_utf16char_t *dst, size_t dst_len, mulle_utf8char_t *src, size_t len);


// UTF16 must be valid
// if len is -1, assume that *s is '\0' terminated
//
size_t  mulle_utf8_length_as_utf16( mulle_utf8char_t *src, size_t len);


static inline size_t  mulle_utf8_max_length_as_utf16( size_t len)
{
   return( len * 4);
}

static inline int  mulle_utf8_has_bom( mulle_utf8char_t *src, size_t len)
{
   if( len < 3)
      return( 0);
   
   return( src[ 0] == 0xEF && src[ 1] == 0xBB && src[ 2] == 0xBF);
}

//
// if len is -1, assume that *s is '\0' terminated
// returns length in characters
// returns size in bytes
// returns pointer to character, that is invalid (first of compound chars)
// TODO: find encoding where nothing needs to be composed

struct mulle_utf8_information
{
   size_t             utf8len;
   size_t             utf16len;
   size_t             utf32len;
   mulle_utf8char_t   *start;         // behind BOM if bommed, otherwise start
   mulle_utf8char_t   *invalid_utf8;  // first fail char
   int                has_bom;
   int                is_ascii;
   int                has_terminating_zero;
};


int  mulle_utf8_information( mulle_utf8char_t *src, size_t len, struct mulle_utf8_information *info);
int  mulle_utf8_is_ascii( mulle_utf8char_t *src, size_t len);


static inline size_t  mulle_utf8_strlen( mulle_utf8char_t *src)
{
   return( strlen( (char *) src));
}


static inline size_t  mulle_utf8_strnlen( mulle_utf8char_t *src, size_t len)
{
   return( strnlen( (char *) src, len));
}


mulle_utf32char_t   mulle_utf8_get_utf32_value( mulle_utf8char_t *s);

int         mulle_utf8_are_valid_extra_chars( char *src, unsigned int len);


// supply a "mulle_buffer" here as "buffer" and mulle_buffer_add_uint16 as the
// callback.
// int == 0 : OK!
int  mulle_utf8_convert_to_utf16_bytebuffer( void *buffer,
                                             void (*adduint16)( void *, uint16_t),
                                             mulle_utf8char_t *src,
                                             size_t len);

// as above, but for utf32
int  mulle_utf8_convert_to_utf32_bytebuffer( void *buffer,
                                             void (*adduint32)( void *, uint32_t),
                                             mulle_utf8char_t *src,
                                             size_t len);


#endif

