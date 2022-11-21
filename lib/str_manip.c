#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str_manip.h"
#include "common.h"

#define strsplitstatic(dest, dest_len, dest_str_len, src, delim) \
{ \
    char src_temp[strlen(src) + 1], *token; \
    int i; \
    sprintf(src_temp, "%s", src); \
    for(i = 0, token = strtok(src_temp, delim); token != NULL; ++i) { \
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

char *str_rep(char *dest, const char *src, const char *r_text, const char *n_text)
{
    char *dest_p = dest, src_temp[strlen(src) + 1], *r_text_p = (char *)r_text;
    char *src_p = &src_temp[0], *n_text_p = (char *)n_text;
    int r_text_len = strlen(r_text);
    sprintf(src_temp, "%s", src);
    while (*src_p != '\0') {
        if (*src_p == *r_text_p)
            if (strisocc(src_p + 1, r_text_p + 1)) {
                while (*n_text_p != '\0')
                    *dest_p++ = *n_text_p++;
                n_text_p = (char *)n_text, src_p += r_text_len;
                continue;
            }
        *dest_p++ = *src_p++;
    }
    *dest_p = '\0';
    return dest;
}

char **str_split(char ***dest, const char *src, const char *delim)
{
    int occur = strisocc(src, delim) + 2;
    char src_temp[strlen(src) + 1], *token;
    char **dest_p = *dest = (char **)malloc(occur * sizeof(char *));
    sprintf(src_temp, "%s", src);
    for(token = strtok(src_temp, delim); token != NULL; token = strtok(NULL, delim), dest_p++) {
        *dest_p = (char *)malloc((strlen(token) + 1) * sizeof(char));
        sprintf(*dest_p, "%s", token);
    }
    *dest_p = NULL;
    return *dest;
}

void str_split_free(char ***dest)
{
    char **dest_p = *dest;
    while (*dest_p != NULL)
        free(*dest_p), dest_p++;
    free(*dest);
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
    int i = 0;
    while (*src != '\0')
        *dest++ = (i++ < n && (*src > 0x60 && *src < 0x7B)) ? (*src++ - 0x20) : *src++;
    *dest = '\0';
    return dest;
}

int str_occ(const char *src, const char *occurrence)
{
    int i;
    for (i = 0; *src != '\0'; src++)
        if (*src == *occurrence)
            if (strisocc(src + 1, occurrence + 1)) ++i;
    return i;
}

char *str_trim(char *dest, const char *src)
{
    char *__dest_p = dest;
    trim_front(src);
    while (*src != '\0') *__dest_p++ = *src++; --__dest_p;
    trim_back(__dest_p); *++__dest_p = '\0';
    return dest;
}

char *str_trimf(char *dest, const char *src)
{
    char *dest_p = dest;
    trim_front(src);
    while (*src != '\0') *dest_p++ = *src++; *dest_p = '\0';
    return dest;
}

char *str_trimb(char *dest, const char *src)
{
    char *dest_p = dest;
    while (*src != '\0') *dest_p++ = *src++; --dest_p;
    trim_back(dest_p); *++dest_p = '\0';
    return dest;
}
