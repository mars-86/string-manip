#include <stdio.h>
#include "str_manip.h"
#include "str_char.h"

char *str_lowercase(char *dest, const char *src)
{
    char *__dest = dest;
    while (*src != '\0')
        *__dest++ = TEST_UPPERCASE(*src) ? TO_LOWERCASE(*src) : *src, src++;
    *__dest = '\0';
    return dest;
}

char *strn_lowercase(char *dest, const char *src, size_t n)
{
    char *__dest = dest;
    int __i = 0;
    while (*src != '\0')
        *__dest++ = (__i++ < n && TEST_UPPERCASE(*src)) ? TO_LOWERCASE(*src++) : *src++;
    *__dest = '\0';
    return dest;
}
