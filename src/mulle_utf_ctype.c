//
//  mulle_utf_ctype.c
//  mulle-utf
//
//  Created by Nat! on 15.04.16.
//  Copyright © 2016 Mulle kybernetiK. All rights reserved.
//

#include "mulle_utf_ctype.h"

#include "mulle_utf_type.h"


int   mulle_utf_is_newline( unichar c)
{
   switch( c)
   {
   case 0xa    :
   case 0xb    :
   case 0xc    :
   case 0xd    :
   case 0x85   :
   case 0x2028 :
   case 0x2029 :
      return( 1);
   }
   return( 0);
}


int   mulle_utf_is_whitespace_or_newline( unichar c)
{
   switch( c)
   {
   case 0x9 :
   case 0xa :
   case 0xb :
   case 0xc :
   case 0xd :
   case 0x20 :
   case 0x85 :
   case 0xa0 :
   case 0x1680 :
   case 0x2000 :
   case 0x2001 :
   case 0x2002 :
   case 0x2003 :
   case 0x2004 :
   case 0x2005 :
   case 0x2006 :
   case 0x2007 :
   case 0x2008 :
   case 0x2009 :
   case 0x200a :
   case 0x200b :
   case 0x2028 :
   case 0x2029 :
   case 0x202f :
   case 0x205f :
   case 0x3000 :
      return( 1);
   }
   return( 0);
}


int   mulle_utf_is_whitespace( unichar c)
{
   switch( c)
   {
   case 0x9 :
   case 0x20 :
   case 0xa0 :
   case 0x1680 :
   case 0x2000 :
   case 0x2001 :
   case 0x2002 :
   case 0x2003 :
   case 0x2004 :
   case 0x2005 :
   case 0x2006 :
   case 0x2007 :
   case 0x2008 :
   case 0x2009 :
   case 0x200a :
   case 0x200b :
   case 0x202f :
   case 0x205f :
   case 0x3000 :
      return( 1);

   default :
      return( 0);
   }
}


int   mulle_utf_is_control( unichar c)
{
   if( c < 0x0020)
      return( 1);
   
   switch( c)
   {
   case 0x007f :
   case 0x0080 :
   case 0x0081 :
   case 0x0082 :
   case 0x0083 :
   case 0x0084 :
   case 0x0085 :
   case 0x0086 :
   case 0x0087 :
   case 0x0088 :
   case 0x0089 :
   case 0x008a :
   case 0x008b :
   case 0x008c :
   case 0x008d :
   case 0x008e :
   case 0x008f :
   case 0x0090 :
   case 0x0091 :
   case 0x0092 :
   case 0x0093 :
   case 0x0094 :
   case 0x0095 :
   case 0x0096 :
   case 0x0097 :
   case 0x0098 :
   case 0x0099 :
   case 0x009a :
   case 0x009b :
   case 0x009c :
   case 0x009d :
   case 0x009e :
   case 0x009f :
   case 0x00ad :
   case 0x0600 :
   case 0x0601 :
   case 0x0602 :
   case 0x0603 :
   case 0x0604 :
   case 0x0605 :
   case 0x061c :
   case 0x06dd :
   case 0x070f :
   case 0x180e :
   case 0x200b :
   case 0x200c :
   case 0x200d :
   case 0x200e :
   case 0x200f :
   case 0x202a :
   case 0x202b :
   case 0x202c :
   case 0x202d :
   case 0x202e :
   case 0x2060 :
   case 0x2061 :
   case 0x2062 :
   case 0x2063 :
   case 0x2064 :
   case 0x2066 :
   case 0x2067 :
   case 0x2068 :
   case 0x2069 :
   case 0x206a :
   case 0x206b :
   case 0x206c :
   case 0x206d :
   case 0x206e :
   case 0x206f :
   case 0xfeff :
   case 0xfff9 :
   case 0xfffa :
   case 0xfffb :
      return( 1);
      
   default :
      return( 0);
   }
}


int   mulle_utf_is_punctuation( unichar c)
{
   if( c < 0x0021)
      return( 0);
   
   if( c > 0xff65)
      return( 0);
   
   switch( c)
   {
      case 0x0021 :
      case 0x0022 :
      case 0x0023 :
      case 0x0025 :
      case 0x0026 :
      case 0x0027 :
      case 0x0028 :
      case 0x0029 :
      case 0x002a :
      case 0x002c :
      case 0x002d :
      case 0x002e :
      case 0x002f :
      case 0x003a :
      case 0x003b :
      case 0x003f :
      case 0x0040 :
      case 0x005b :
      case 0x005c :
      case 0x005d :
      case 0x005f :
      case 0x007b :
      case 0x007d :
      case 0x00a1 :
      case 0x00a7 :
      case 0x00ab :
      case 0x00b6 :
      case 0x00b7 :
      case 0x00bb :
      case 0x00bf :
      case 0x037e :
      case 0x0387 :
      case 0x055a :
      case 0x055b :
      case 0x055c :
      case 0x055d :
      case 0x055e :
      case 0x055f :
      case 0x0589 :
      case 0x058a :
      case 0x05be :
      case 0x05c0 :
      case 0x05c3 :
      case 0x05c6 :
      case 0x05f3 :
      case 0x05f4 :
      case 0x0609 :
      case 0x060a :
      case 0x060c :
      case 0x060d :
      case 0x061b :
      case 0x061e :
      case 0x061f :
      case 0x066a :
      case 0x066b :
      case 0x066c :
      case 0x066d :
      case 0x06d4 :
      case 0x0700 :
      case 0x0701 :
      case 0x0702 :
      case 0x0703 :
      case 0x0704 :
      case 0x0705 :
      case 0x0706 :
      case 0x0707 :
      case 0x0708 :
      case 0x0709 :
      case 0x070a :
      case 0x070b :
      case 0x070c :
      case 0x070d :
      case 0x07f7 :
      case 0x07f8 :
      case 0x07f9 :
      case 0x0830 :
      case 0x0831 :
      case 0x0832 :
      case 0x0833 :
      case 0x0834 :
      case 0x0835 :
      case 0x0836 :
      case 0x0837 :
      case 0x0838 :
      case 0x0839 :
      case 0x083a :
      case 0x083b :
      case 0x083c :
      case 0x083d :
      case 0x083e :
      case 0x085e :
      case 0x0964 :
      case 0x0965 :
      case 0x0970 :
      case 0x0af0 :
      case 0x0df4 :
      case 0x0e4f :
      case 0x0e5a :
      case 0x0e5b :
      case 0x0f04 :
      case 0x0f05 :
      case 0x0f06 :
      case 0x0f07 :
      case 0x0f08 :
      case 0x0f09 :
      case 0x0f0a :
      case 0x0f0b :
      case 0x0f0c :
      case 0x0f0d :
      case 0x0f0e :
      case 0x0f0f :
      case 0x0f10 :
      case 0x0f11 :
      case 0x0f12 :
      case 0x0f14 :
      case 0x0f3a :
      case 0x0f3b :
      case 0x0f3c :
      case 0x0f3d :
      case 0x0f85 :
      case 0x0fd0 :
      case 0x0fd1 :
      case 0x0fd2 :
      case 0x0fd3 :
      case 0x0fd4 :
      case 0x0fd9 :
      case 0x0fda :
      case 0x104a :
      case 0x104b :
      case 0x104c :
      case 0x104d :
      case 0x104e :
      case 0x104f :
      case 0x10fb :
      case 0x1360 :
      case 0x1361 :
      case 0x1362 :
      case 0x1363 :
      case 0x1364 :
      case 0x1365 :
      case 0x1366 :
      case 0x1367 :
      case 0x1368 :
      case 0x1400 :
      case 0x166d :
      case 0x166e :
      case 0x169b :
      case 0x169c :
      case 0x16eb :
      case 0x16ec :
      case 0x16ed :
      case 0x1735 :
      case 0x1736 :
      case 0x17d4 :
      case 0x17d5 :
      case 0x17d6 :
      case 0x17d8 :
      case 0x17d9 :
      case 0x17da :
      case 0x1800 :
      case 0x1801 :
      case 0x1802 :
      case 0x1803 :
      case 0x1804 :
      case 0x1805 :
      case 0x1806 :
      case 0x1807 :
      case 0x1808 :
      case 0x1809 :
      case 0x180a :
      case 0x1944 :
      case 0x1945 :
      case 0x1a1e :
      case 0x1a1f :
      case 0x1aa0 :
      case 0x1aa1 :
      case 0x1aa2 :
      case 0x1aa3 :
      case 0x1aa4 :
      case 0x1aa5 :
      case 0x1aa6 :
      case 0x1aa8 :
      case 0x1aa9 :
      case 0x1aaa :
      case 0x1aab :
      case 0x1aac :
      case 0x1aad :
      case 0x1b5a :
      case 0x1b5b :
      case 0x1b5c :
      case 0x1b5d :
      case 0x1b5e :
      case 0x1b5f :
      case 0x1b60 :
      case 0x1bfc :
      case 0x1bfd :
      case 0x1bfe :
      case 0x1bff :
      case 0x1c3b :
      case 0x1c3c :
      case 0x1c3d :
      case 0x1c3e :
      case 0x1c3f :
      case 0x1c7e :
      case 0x1c7f :
      case 0x1cc0 :
      case 0x1cc1 :
      case 0x1cc2 :
      case 0x1cc3 :
      case 0x1cc4 :
      case 0x1cc5 :
      case 0x1cc6 :
      case 0x1cc7 :
      case 0x1cd3 :
      case 0x2010 :
      case 0x2011 :
      case 0x2012 :
      case 0x2013 :
      case 0x2014 :
      case 0x2015 :
      case 0x2016 :
      case 0x2017 :
      case 0x2018 :
      case 0x2019 :
      case 0x201a :
      case 0x201b :
      case 0x201c :
      case 0x201d :
      case 0x201e :
      case 0x201f :
      case 0x2020 :
      case 0x2021 :
      case 0x2022 :
      case 0x2023 :
      case 0x2024 :
      case 0x2025 :
      case 0x2026 :
      case 0x2027 :
      case 0x2030 :
      case 0x2031 :
      case 0x2032 :
      case 0x2033 :
      case 0x2034 :
      case 0x2035 :
      case 0x2036 :
      case 0x2037 :
      case 0x2038 :
      case 0x2039 :
      case 0x203a :
      case 0x203b :
      case 0x203c :
      case 0x203d :
      case 0x203e :
      case 0x203f :
      case 0x2040 :
      case 0x2041 :
      case 0x2042 :
      case 0x2043 :
      case 0x2045 :
      case 0x2046 :
      case 0x2047 :
      case 0x2048 :
      case 0x2049 :
      case 0x204a :
      case 0x204b :
      case 0x204c :
      case 0x204d :
      case 0x204e :
      case 0x204f :
      case 0x2050 :
      case 0x2051 :
      case 0x2053 :
      case 0x2054 :
      case 0x2055 :
      case 0x2056 :
      case 0x2057 :
      case 0x2058 :
      case 0x2059 :
      case 0x205a :
      case 0x205b :
      case 0x205c :
      case 0x205d :
      case 0x205e :
      case 0x207d :
      case 0x207e :
      case 0x208d :
      case 0x208e :
      case 0x2308 :
      case 0x2309 :
      case 0x230a :
      case 0x230b :
      case 0x2329 :
      case 0x232a :
      case 0x2768 :
      case 0x2769 :
      case 0x276a :
      case 0x276b :
      case 0x276c :
      case 0x276d :
      case 0x276e :
      case 0x276f :
      case 0x2770 :
      case 0x2771 :
      case 0x2772 :
      case 0x2773 :
      case 0x2774 :
      case 0x2775 :
      case 0x27c5 :
      case 0x27c6 :
      case 0x27e6 :
      case 0x27e7 :
      case 0x27e8 :
      case 0x27e9 :
      case 0x27ea :
      case 0x27eb :
      case 0x27ec :
      case 0x27ed :
      case 0x27ee :
      case 0x27ef :
      case 0x2983 :
      case 0x2984 :
      case 0x2985 :
      case 0x2986 :
      case 0x2987 :
      case 0x2988 :
      case 0x2989 :
      case 0x298a :
      case 0x298b :
      case 0x298c :
      case 0x298d :
      case 0x298e :
      case 0x298f :
      case 0x2990 :
      case 0x2991 :
      case 0x2992 :
      case 0x2993 :
      case 0x2994 :
      case 0x2995 :
      case 0x2996 :
      case 0x2997 :
      case 0x2998 :
      case 0x29d8 :
      case 0x29d9 :
      case 0x29da :
      case 0x29db :
      case 0x29fc :
      case 0x29fd :
      case 0x2cf9 :
      case 0x2cfa :
      case 0x2cfb :
      case 0x2cfc :
      case 0x2cfe :
      case 0x2cff :
      case 0x2d70 :
      case 0x2e00 :
      case 0x2e01 :
      case 0x2e02 :
      case 0x2e03 :
      case 0x2e04 :
      case 0x2e05 :
      case 0x2e06 :
      case 0x2e07 :
      case 0x2e08 :
      case 0x2e09 :
      case 0x2e0a :
      case 0x2e0b :
      case 0x2e0c :
      case 0x2e0d :
      case 0x2e0e :
      case 0x2e0f :
      case 0x2e10 :
      case 0x2e11 :
      case 0x2e12 :
      case 0x2e13 :
      case 0x2e14 :
      case 0x2e15 :
      case 0x2e16 :
      case 0x2e17 :
      case 0x2e18 :
      case 0x2e19 :
      case 0x2e1a :
      case 0x2e1b :
      case 0x2e1c :
      case 0x2e1d :
      case 0x2e1e :
      case 0x2e1f :
      case 0x2e20 :
      case 0x2e21 :
      case 0x2e22 :
      case 0x2e23 :
      case 0x2e24 :
      case 0x2e25 :
      case 0x2e26 :
      case 0x2e27 :
      case 0x2e28 :
      case 0x2e29 :
      case 0x2e2a :
      case 0x2e2b :
      case 0x2e2c :
      case 0x2e2d :
      case 0x2e2e :
      case 0x2e30 :
      case 0x2e31 :
      case 0x2e32 :
      case 0x2e33 :
      case 0x2e34 :
      case 0x2e35 :
      case 0x2e36 :
      case 0x2e37 :
      case 0x2e38 :
      case 0x2e39 :
      case 0x2e3a :
      case 0x2e3b :
      case 0x2e3c :
      case 0x2e3d :
      case 0x2e3e :
      case 0x2e3f :
      case 0x2e40 :
      case 0x2e41 :
      case 0x2e42 :
      case 0x3001 :
      case 0x3002 :
      case 0x3003 :
      case 0x3008 :
      case 0x3009 :
      case 0x300a :
      case 0x300b :
      case 0x300c :
      case 0x300d :
      case 0x300e :
      case 0x300f :
      case 0x3010 :
      case 0x3011 :
      case 0x3014 :
      case 0x3015 :
      case 0x3016 :
      case 0x3017 :
      case 0x3018 :
      case 0x3019 :
      case 0x301a :
      case 0x301b :
      case 0x301c :
      case 0x301d :
      case 0x301e :
      case 0x301f :
      case 0x3030 :
      case 0x303d :
      case 0x30a0 :
      case 0x30fb :
      case 0xa4fe :
      case 0xa4ff :
      case 0xa60d :
      case 0xa60e :
      case 0xa60f :
      case 0xa673 :
      case 0xa67e :
      case 0xa6f2 :
      case 0xa6f3 :
      case 0xa6f4 :
      case 0xa6f5 :
      case 0xa6f6 :
      case 0xa6f7 :
      case 0xa874 :
      case 0xa875 :
      case 0xa876 :
      case 0xa877 :
      case 0xa8ce :
      case 0xa8cf :
      case 0xa8f8 :
      case 0xa8f9 :
      case 0xa8fa :
      case 0xa92e :
      case 0xa92f :
      case 0xa95f :
      case 0xa9c1 :
      case 0xa9c2 :
      case 0xa9c3 :
      case 0xa9c4 :
      case 0xa9c5 :
      case 0xa9c6 :
      case 0xa9c7 :
      case 0xa9c8 :
      case 0xa9c9 :
      case 0xa9ca :
      case 0xa9cb :
      case 0xa9cc :
      case 0xa9cd :
      case 0xa9de :
      case 0xa9df :
      case 0xaa5c :
      case 0xaa5d :
      case 0xaa5e :
      case 0xaa5f :
      case 0xaade :
      case 0xaadf :
      case 0xaaf0 :
      case 0xaaf1 :
      case 0xabeb :
      case 0xfd3e :
      case 0xfd3f :
      case 0xfe10 :
      case 0xfe11 :
      case 0xfe12 :
      case 0xfe13 :
      case 0xfe14 :
      case 0xfe15 :
      case 0xfe16 :
      case 0xfe17 :
      case 0xfe18 :
      case 0xfe19 :
      case 0xfe30 :
      case 0xfe31 :
      case 0xfe32 :
      case 0xfe33 :
      case 0xfe34 :
      case 0xfe35 :
      case 0xfe36 :
      case 0xfe37 :
      case 0xfe38 :
      case 0xfe39 :
      case 0xfe3a :
      case 0xfe3b :
      case 0xfe3c :
      case 0xfe3d :
      case 0xfe3e :
      case 0xfe3f :
      case 0xfe40 :
      case 0xfe41 :
      case 0xfe42 :
      case 0xfe43 :
      case 0xfe44 :
      case 0xfe45 :
      case 0xfe46 :
      case 0xfe47 :
      case 0xfe48 :
      case 0xfe49 :
      case 0xfe4a :
      case 0xfe4b :
      case 0xfe4c :
      case 0xfe4d :
      case 0xfe4e :
      case 0xfe4f :
      case 0xfe50 :
      case 0xfe51 :
      case 0xfe52 :
      case 0xfe54 :
      case 0xfe55 :
      case 0xfe56 :
      case 0xfe57 :
      case 0xfe58 :
      case 0xfe59 :
      case 0xfe5a :
      case 0xfe5b :
      case 0xfe5c :
      case 0xfe5d :
      case 0xfe5e :
      case 0xfe5f :
      case 0xfe60 :
      case 0xfe61 :
      case 0xfe63 :
      case 0xfe68 :
      case 0xfe6a :
      case 0xfe6b :
      case 0xff01 :
      case 0xff02 :
      case 0xff03 :
      case 0xff05 :
      case 0xff06 :
      case 0xff07 :
      case 0xff08 :
      case 0xff09 :
      case 0xff0a :
      case 0xff0c :
      case 0xff0d :
      case 0xff0e :
      case 0xff0f :
      case 0xff1a :
      case 0xff1b :
      case 0xff1f :
      case 0xff20 :
      case 0xff3b :
      case 0xff3c :
      case 0xff3d :
      case 0xff3f :
      case 0xff5b :
      case 0xff5d :
      case 0xff5f :
      case 0xff60 :
      case 0xff61 :
      case 0xff62 :
      case 0xff63 :
      case 0xff64 :
         return( 1);
         
      default :
         return( 0);
   }
}

