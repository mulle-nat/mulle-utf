//
//  mulle_utf_is_decimaldigit.c
//  mulle-utf
//
//  Created by Nat! on 15.04.16.
//  Copyright © 2016 Mulle kybernetiK. All rights reserved.
//

#include "mulle_utf_is_decimaldigit.h"


int   mulle_utf_is_decimaldigit( unichar c)
{
   if( c < 0x0030)
      return( 0);

   if( c > 0xff19)
      return( 0);

   switch( c)
   {
   case 0x0030 :
   case 0x0031 :
   case 0x0032 :
   case 0x0033 :
   case 0x0034 :
   case 0x0035 :
   case 0x0036 :
   case 0x0037 :
   case 0x0038 :
   case 0x0039 :
   case 0x0660 :
   case 0x0661 :
   case 0x0662 :
   case 0x0663 :
   case 0x0664 :
   case 0x0665 :
   case 0x0666 :
   case 0x0667 :
   case 0x0668 :
   case 0x0669 :
   case 0x06f0 :
   case 0x06f1 :
   case 0x06f2 :
   case 0x06f3 :
   case 0x06f4 :
   case 0x06f5 :
   case 0x06f6 :
   case 0x06f7 :
   case 0x06f8 :
   case 0x06f9 :
   case 0x07c0 :
   case 0x07c1 :
   case 0x07c2 :
   case 0x07c3 :
   case 0x07c4 :
   case 0x07c5 :
   case 0x07c6 :
   case 0x07c7 :
   case 0x07c8 :
   case 0x07c9 :
   case 0x0966 :
   case 0x0967 :
   case 0x0968 :
   case 0x0969 :
   case 0x096a :
   case 0x096b :
   case 0x096c :
   case 0x096d :
   case 0x096e :
   case 0x096f :
   case 0x09e6 :
   case 0x09e7 :
   case 0x09e8 :
   case 0x09e9 :
   case 0x09ea :
   case 0x09eb :
   case 0x09ec :
   case 0x09ed :
   case 0x09ee :
   case 0x09ef :
   case 0x0a66 :
   case 0x0a67 :
   case 0x0a68 :
   case 0x0a69 :
   case 0x0a6a :
   case 0x0a6b :
   case 0x0a6c :
   case 0x0a6d :
   case 0x0a6e :
   case 0x0a6f :
   case 0x0ae6 :
   case 0x0ae7 :
   case 0x0ae8 :
   case 0x0ae9 :
   case 0x0aea :
   case 0x0aeb :
   case 0x0aec :
   case 0x0aed :
   case 0x0aee :
   case 0x0aef :
   case 0x0b66 :
   case 0x0b67 :
   case 0x0b68 :
   case 0x0b69 :
   case 0x0b6a :
   case 0x0b6b :
   case 0x0b6c :
   case 0x0b6d :
   case 0x0b6e :
   case 0x0b6f :
   case 0x0be6 :
   case 0x0be7 :
   case 0x0be8 :
   case 0x0be9 :
   case 0x0bea :
   case 0x0beb :
   case 0x0bec :
   case 0x0bed :
   case 0x0bee :
   case 0x0bef :
   case 0x0c66 :
   case 0x0c67 :
   case 0x0c68 :
   case 0x0c69 :
   case 0x0c6a :
   case 0x0c6b :
   case 0x0c6c :
   case 0x0c6d :
   case 0x0c6e :
   case 0x0c6f :
   case 0x0ce6 :
   case 0x0ce7 :
   case 0x0ce8 :
   case 0x0ce9 :
   case 0x0cea :
   case 0x0ceb :
   case 0x0cec :
   case 0x0ced :
   case 0x0cee :
   case 0x0cef :
   case 0x0d66 :
   case 0x0d67 :
   case 0x0d68 :
   case 0x0d69 :
   case 0x0d6a :
   case 0x0d6b :
   case 0x0d6c :
   case 0x0d6d :
   case 0x0d6e :
   case 0x0d6f :
   case 0x0de6 :
   case 0x0de7 :
   case 0x0de8 :
   case 0x0de9 :
   case 0x0dea :
   case 0x0deb :
   case 0x0dec :
   case 0x0ded :
   case 0x0dee :
   case 0x0def :
   case 0x0e50 :
   case 0x0e51 :
   case 0x0e52 :
   case 0x0e53 :
   case 0x0e54 :
   case 0x0e55 :
   case 0x0e56 :
   case 0x0e57 :
   case 0x0e58 :
   case 0x0e59 :
   case 0x0ed0 :
   case 0x0ed1 :
   case 0x0ed2 :
   case 0x0ed3 :
   case 0x0ed4 :
   case 0x0ed5 :
   case 0x0ed6 :
   case 0x0ed7 :
   case 0x0ed8 :
   case 0x0ed9 :
   case 0x0f20 :
   case 0x0f21 :
   case 0x0f22 :
   case 0x0f23 :
   case 0x0f24 :
   case 0x0f25 :
   case 0x0f26 :
   case 0x0f27 :
   case 0x0f28 :
   case 0x0f29 :
   case 0x1040 :
   case 0x1041 :
   case 0x1042 :
   case 0x1043 :
   case 0x1044 :
   case 0x1045 :
   case 0x1046 :
   case 0x1047 :
   case 0x1048 :
   case 0x1049 :
   case 0x1090 :
   case 0x1091 :
   case 0x1092 :
   case 0x1093 :
   case 0x1094 :
   case 0x1095 :
   case 0x1096 :
   case 0x1097 :
   case 0x1098 :
   case 0x1099 :
   case 0x17e0 :
   case 0x17e1 :
   case 0x17e2 :
   case 0x17e3 :
   case 0x17e4 :
   case 0x17e5 :
   case 0x17e6 :
   case 0x17e7 :
   case 0x17e8 :
   case 0x17e9 :
   case 0x1810 :
   case 0x1811 :
   case 0x1812 :
   case 0x1813 :
   case 0x1814 :
   case 0x1815 :
   case 0x1816 :
   case 0x1817 :
   case 0x1818 :
   case 0x1819 :
   case 0x1946 :
   case 0x1947 :
   case 0x1948 :
   case 0x1949 :
   case 0x194a :
   case 0x194b :
   case 0x194c :
   case 0x194d :
   case 0x194e :
   case 0x194f :
   case 0x19d0 :
   case 0x19d1 :
   case 0x19d2 :
   case 0x19d3 :
   case 0x19d4 :
   case 0x19d5 :
   case 0x19d6 :
   case 0x19d7 :
   case 0x19d8 :
   case 0x19d9 :
   case 0x1a80 :
   case 0x1a81 :
   case 0x1a82 :
   case 0x1a83 :
   case 0x1a84 :
   case 0x1a85 :
   case 0x1a86 :
   case 0x1a87 :
   case 0x1a88 :
   case 0x1a89 :
   case 0x1a90 :
   case 0x1a91 :
   case 0x1a92 :
   case 0x1a93 :
   case 0x1a94 :
   case 0x1a95 :
   case 0x1a96 :
   case 0x1a97 :
   case 0x1a98 :
   case 0x1a99 :
   case 0x1b50 :
   case 0x1b51 :
   case 0x1b52 :
   case 0x1b53 :
   case 0x1b54 :
   case 0x1b55 :
   case 0x1b56 :
   case 0x1b57 :
   case 0x1b58 :
   case 0x1b59 :
   case 0x1bb0 :
   case 0x1bb1 :
   case 0x1bb2 :
   case 0x1bb3 :
   case 0x1bb4 :
   case 0x1bb5 :
   case 0x1bb6 :
   case 0x1bb7 :
   case 0x1bb8 :
   case 0x1bb9 :
   case 0x1c40 :
   case 0x1c41 :
   case 0x1c42 :
   case 0x1c43 :
   case 0x1c44 :
   case 0x1c45 :
   case 0x1c46 :
   case 0x1c47 :
   case 0x1c48 :
   case 0x1c49 :
   case 0x1c50 :
   case 0x1c51 :
   case 0x1c52 :
   case 0x1c53 :
   case 0x1c54 :
   case 0x1c55 :
   case 0x1c56 :
   case 0x1c57 :
   case 0x1c58 :
   case 0x1c59 :
   case 0xa620 :
   case 0xa621 :
   case 0xa622 :
   case 0xa623 :
   case 0xa624 :
   case 0xa625 :
   case 0xa626 :
   case 0xa627 :
   case 0xa628 :
   case 0xa629 :
   case 0xa8d0 :
   case 0xa8d1 :
   case 0xa8d2 :
   case 0xa8d3 :
   case 0xa8d4 :
   case 0xa8d5 :
   case 0xa8d6 :
   case 0xa8d7 :
   case 0xa8d8 :
   case 0xa8d9 :
   case 0xa900 :
   case 0xa901 :
   case 0xa902 :
   case 0xa903 :
   case 0xa904 :
   case 0xa905 :
   case 0xa906 :
   case 0xa907 :
   case 0xa908 :
   case 0xa909 :
   case 0xa9d0 :
   case 0xa9d1 :
   case 0xa9d2 :
   case 0xa9d3 :
   case 0xa9d4 :
   case 0xa9d5 :
   case 0xa9d6 :
   case 0xa9d7 :
   case 0xa9d8 :
   case 0xa9d9 :
   case 0xa9f0 :
   case 0xa9f1 :
   case 0xa9f2 :
   case 0xa9f3 :
   case 0xa9f4 :
   case 0xa9f5 :
   case 0xa9f6 :
   case 0xa9f7 :
   case 0xa9f8 :
   case 0xa9f9 :
   case 0xaa50 :
   case 0xaa51 :
   case 0xaa52 :
   case 0xaa53 :
   case 0xaa54 :
   case 0xaa55 :
   case 0xaa56 :
   case 0xaa57 :
   case 0xaa58 :
   case 0xaa59 :
   case 0xabf0 :
   case 0xabf1 :
   case 0xabf2 :
   case 0xabf3 :
   case 0xabf4 :
   case 0xabf5 :
   case 0xabf6 :
   case 0xabf7 :
   case 0xabf8 :
   case 0xabf9 :
   case 0xff10 :
   case 0xff11 :
   case 0xff12 :
   case 0xff13 :
   case 0xff14 :
   case 0xff15 :
   case 0xff16 :
   case 0xff17 :
   case 0xff18 :
      return( 1);

    default :
       return( 0);
   }
}
