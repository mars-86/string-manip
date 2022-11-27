#ifndef _LIB_STR_TRIM_INCLUDED_H_
#define _LIB_STR_TRIM_INCLUDED_H_

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

#endif // _LIB_STR_TRIM_INCLUDED_H_
