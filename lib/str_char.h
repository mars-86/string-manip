#ifndef __LIB_STR_CHAR_INCLUDED_H__
#define __LIB_STR_CHAR_INCLUDED_H__

#define TEST_LOWERCASE(c) (c > 0x60 && c < 0x7B)
#define TEST_UPPERCASE(c) (c > 0x40 && c < 0x5B)

#define TO_LOWERCASE(c) (c + 0x20)
#define TO_UPPERCASE(c) (c - 0x20)

#endif // __LIB_STR_CHAR_INCLUDED_H__
