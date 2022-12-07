#include <stdio.h>
#include "str_manip.h"
#include "str_char.h"

char *str_uppercase(char *dest, const char *src)
{
    char *__dest = dest;
    while (*src != '\0')
        *__dest++ = TEST_LOWERCASE(*src) ? TO_UPPERCASE(*src++) : *src++;
    *__dest = '\0';
    return dest;
}

char *strn_uppercase(char *dest, const char *src, size_t n)
{
    char *__dest = dest;
    int __i = 0;
    while (*src != '\0')
        *__dest++ = (__i++ < n && TEST_LOWERCASE(*src)) ? TO_UPPERCASE(*src++) : *src++;
    *__dest = '\0';
    return dest;
}
