//
//  mulle_utf_is_control.h
//  mulle-utf
//
//  Created by Nat! on 2016-04-15 17:24:35 +0200.
//  Copyright © 2016 Mulle kybernetiK. All rights reserved.
//

#ifndef mulle_utf_is_control_h__
#define mulle_utf_is_control_h__

#include "mulle_utf.h"


int   mulle_utf16_is_control( mulle_utf16char_t c);
int   mulle_utf32_is_control( mulle_utf32char_t c);
int   mulle_utf_is_controlplane( unsigned int plane);

#endif /* mulle_utf_is_control_h */
