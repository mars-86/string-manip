#include <stdio.h>
#include <string.h>
#include "str_manip.h"
#include "byte_copy.h"

char *str_pad_front(char *dest, const char *src, const char *ptext, int padding)
{
    char *__dest = dest;
    size_t __src_len = strlen(src);
    if (padding < __src_len) {
        COPY_BYTES_FWD(__dest, src); *__dest ='\0';
    } else {
        const char *__ptext = ptext;
        int i = 0, __padding_chars = padding - __src_len;
        while (i < __padding_chars) {
            while(*__ptext != '\0' && i++ < __padding_chars)
                *__dest++ = *__ptext++;
            __ptext = ptext;
        }
        COPY_BYTES_FWD(__dest, src); *__dest ='\0';
    }
    return dest;
}

char *str_pad_back(char *dest, const char *src, const char *ptext, int padding)
{
    char *__dest = dest;
    size_t __src_len = strlen(src);
    if (padding < __src_len) {
        COPY_BYTES_FWD(__dest, src); *__dest ='\0';
    } else {
        const char *__ptext = ptext;
        int i = 0, __padding_chars = padding - __src_len;
        COPY_BYTES_FWD(__dest, src);
        while (i < __padding_chars) {
            while(*__ptext != '\0' && i++ < __padding_chars)
                *__dest++ = *__ptext++;
            __ptext = ptext;
        }
        *__dest ='\0';
    }
    return dest;
}
