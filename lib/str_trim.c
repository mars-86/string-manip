#include "str_manip.h"
#include "str_trim.h"

char *str_trim(char *dest, const char *src)
{
    char *__dest = dest;
    TRIM_FRONT(src);
    while (*src != '\0') *__dest++ = *src++; --__dest;
    TRIM_BACK(__dest); *++__dest = '\0';
    return dest;
}

char *str_trim_front(char *dest, const char *src)
{
    char *__dest = dest;
    TRIM_FRONT(src);
    while (*src != '\0') *__dest++ = *src++; *__dest = '\0';
    return dest;
}

char *str_trim_back(char *dest, const char *src)
{
    char *__dest = dest;
    while (*src != '\0') *__dest++ = *src++; --__dest;
    TRIM_BACK(__dest); *++__dest = '\0';
    return dest;
}
