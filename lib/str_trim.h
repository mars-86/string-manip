#ifndef __LIB_STR_TRIM_INCLUDED_H__
#define __LIB_STR_TRIM_INCLUDED_H__

#define TRIM_TEST_N(src) src != ' ' && src != '\n' && src != '\t'
#define TRIM_TEST(src) src == ' ' || src == '\n' || src == '\t'

#define TRIM_FRONT(src)                 \
    do {                                \
        while (TRIM_TEST(*src)) ++src;  \
    } while (0)

#define TRIM_BACK(src)                  \
    do {                                \
        while (TRIM_TEST(*src)) --src;  \
    } while (0)

#endif // __LIB_STR_TRIM_INCLUDED_H__
