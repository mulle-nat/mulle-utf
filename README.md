# mulle-utf

a C (C99) library to handle unicode strings.


> Naming: UTF is a transfer encoding for Unicode. So everything
eventually maps to (32 bit) unicode characters. That operations are done on UTF directly is kinda questionable, but I believe common.


>> TODO (maybe): split this up into mulle_unicode, mulle_unitype, mulle_utf


## mulle_utf_information


### Lenient

If len is zero, then the character pointer may be NULL

### Allowed Characters

mulle_utf always preempts on zero chars. "ha\0ha" will have a string length
of 2 in any encoding.

mulle_utf does not like UTF16 surrogate pair character codes in UTF8 or
UTF32. These kind of strings are considered invalid.


### Always skips the BOM

If you use mulle_utf32_information and friends to figure out the lengths of
strings in various decodings, take note that the length is computed with the
BOM skipped.

Common error:

```
   ...
   mulle_utf32_information( s, len, &info);
   ...
   mulle_utf32_convert_to_utf16_bytebuffer( &buffer,
                                            (void *) mulle_buffer_add_bytes,
                                            s,
                                            len);
```

It must be coded as:

```
   mulle_utf32_convert_to_utf16_bytebuffer( &buffer,
                                            (void *) mulle_buffer_add_bytes,
                                            info.start,
                                            info.utf32len);
```

Only now is the possible BOM of the UTF32 string skipped properly and the
nummer of converted characters (info.utf16len) will match.


## conversion routines

* do not look for BOMs



