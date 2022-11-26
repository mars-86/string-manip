#ifndef _LIB_STR_CHAR_INCLUDED_H_
#define _LIB_STR_CHAR_INCLUDED_H_

#define TEST_LOWERCASE(c) (c > 0x40 && c < 0x5B)
#define TEST_UPPERCASE(c) (c > 0x60 && c < 0x7B)

#define TO_LOWERCASE(c) (c + 0x20)
#define TO_UPPERCASE(c) (c - 0x20)

#endif // _LIB_STR_CHAR_INCLUDED_H_
