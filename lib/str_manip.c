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

char *str_replace(char *dest, const char *src, const char *rtext, const char *ntext)
{
    char *__dest = dest;
    const char *__src = src, *__rtext = rtext, *__ntext = ntext;
    size_t r_text_len = strlen(rtext);
    while (*__src != '\0') {
        if (*__src == *__rtext)
            if (strisocc(__src + 1, __rtext + 1)) {
                while (*__ntext != '\0')
                    *__dest++ = *__ntext++;
                __ntext = ntext, __src += r_text_len;
                continue;
            }
        *__dest++ = *__src++;
    }
    *__dest = '\0';
    return dest;
}

char **str_split(char ***dest, const char *src, const char *delim)
{
    int __occur = strisocc(src, delim) + 2;
    char __src_temp[strlen(src) + 1], *__token;
    char **__dest = *dest = (char **)malloc(__occur * sizeof(char *));
    sprintf(__src_temp, "%s", src);
    for(__token = strtok(__src_temp, delim); __token != NULL; __token = strtok(NULL, delim), __dest++) {
        *__dest = (char *)malloc((strlen(__token) + 1) * sizeof(char));
        sprintf(*__dest, "%s", __token);
    }
    *__dest = NULL;
    return *dest;
}

void str_split_free(char ***dest)
{
    char **__dest = *dest;
    while (*__dest != NULL)
        free(*__dest), __dest++;
    free(*dest);
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

char *str_trim(char *dest, const char *src)
{
    char *__dest = dest;
    trim_front(src);
    while (*src != '\0') *__dest++ = *src++; --__dest;
    trim_back(__dest); *++__dest = '\0';
    return dest;
}

char *str_trimf(char *dest, const char *src)
{
    char *__dest = dest;
    trim_front(src);
    while (*src != '\0') *__dest++ = *src++; *__dest = '\0';
    return dest;
}

char *str_trimb(char *dest, const char *src)
{
    char *__dest = dest;
    while (*src != '\0') *__dest++ = *src++; --__dest;
    trim_back(__dest); *++__dest = '\0';
    return dest;
}

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
