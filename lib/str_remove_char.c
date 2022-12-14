#include "str_manip.h"

char *str_remove_char(char *dest, const char *src, const char c)
{
    char *__dest;
    for (__dest = dest; *src != '\0'; src++)
        if (*src != c) *__dest++ = *src;
    *__dest = '\0';

    return dest;
}
