#include <stdio.h>
#include <str_manip.h>
#include "str_char.h"

char *str_lowercase(char *dest, const char *src)
{
    while (*src != '\0')
        *dest++ = TEST_UPPERCASE(*src) ? TO_LOWERCASE(*src++) : *src++;
    *dest = '\0';
    return dest;
}

char *strn_lowercase(char *dest, const char *src, size_t n)
{
    int __i = 0;
    while (*src != '\0')
        *dest++ = (__i++ < n && TEST_UPPERCASE(*src)) ? TO_LOWERCASE(*src++) : *src++;
    *dest = '\0';
    return dest;
}
