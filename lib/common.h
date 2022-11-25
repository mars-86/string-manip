#ifndef _LIB_COMMON_INCLUDED_H_
#define _LIB_COMMON_INCLUDED_H_

#define COPY_BYTES_FWD(dest, src)   \
    do {                            \
        while (*src != '\0')        \
            *dest++ = *src++;       \
    } while (0)

#define trim_test_n(src) src != ' ' && src != '\n' && src != '\t'
#define trim_test(src) src == ' ' || src == '\n' || src == '\t'

#define trim_front(src) while (trim_test(*src)) ++src
#define trim_back(src) while (trim_test(*src)) --src

#endif // _LIB_COMMON_INCLUDED_H_
