#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str_manip.h"
#include "common.h"

#define COPY_BYTES_FWD(dest, src) \
    do { \
        while (*src != '\0') \
            *dest++ = *src++; \
    } while (0)

#define strsplitstatic(dest, dest_len, dest_str_len, src, delim) \
{ \
    char __src_temp[strlen(src) + 1], *token; \
    int i; \
    sprintf(__src_temp, "%s", src); \
    for(i = 0, token = strtok(__src_temp, delim); token != NULL; ++i) { \
        sprintf(dest[i], "%s", token); \
        token = strtok(NULL, delim); \
    } \
}

static inline int strisocc(const char *src, const char *occurrence)
{
    while (*occurrence != '\0')
        if (*occurrence++ != *src++) return 0;
    return 1;
}

char *str_lowerc(char *dest, const char *src)
{
    while (*src != '\0')
        *dest++ = (*src > 0x40 && *src < 0x5B) ? (*src++ + 0x20) : *src++;
    *dest = '\0';
    return dest;
}

char *strn_lowerc(char *dest, const char *src, size_t n)
{
    int __i = 0;
    while (*src != '\0')
        *dest++ = (__i++ < n && (*src > 0x40 && *src < 0x5B)) ? (*src++ + 0x20) : *src++;
    *dest = '\0';
    return dest;
}

char *str_upperc(char *dest, const char *src)
{
    while (*src != '\0')
        *dest++ = (*src > 0x60 && *src < 0x7B) ? (*src++ - 0x20) : *src++;
    *dest = '\0';
    return dest;
}

char *strn_upperc(char *dest, const char *src, size_t n)
{
    int __i = 0;
    while (*src != '\0')
        *dest++ = (__i++ < n && (*src > 0x60 && *src < 0x7B)) ? (*src++ - 0x20) : *src++;
    *dest = '\0';
    return dest;
}

int str_occ(const char *src, const char *occurrence)
{
    int __i;
    for (__i = 0; *src != '\0'; src++)
        if (*src == *occurrence)
            if (strisocc(src + 1, occurrence + 1)) ++__i;
    return __i;
}
