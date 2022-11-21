#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mem_manip.h"
#include "common.h"

#define mem_split_static(dest, dest_len, dest_str_len, src, delim) \
{ \
    char src_temp[strlen(src) + 1], *token; \
    int i; \
    sprintf(src_temp, "%s", src); \
    for(i = 0, token = strtok(src_temp, delim); token != NULL; ++i) { \
        sprintf(dest[i], "%s", token); \
        token = strtok(NULL, delim); \
    } \
}

int is_occurrence(const char *src, const char *occurrence)
{
    while (*occurrence != '\0')
        if (*occurrence++ != *src++) return 0;
    return 1;
}

char *mem_replace(char *dest, const char *src, const char *r_text, const char *n_text)
{
    char *dest_p = dest;
    const char *src_p = src, *r_text_p = r_text, *n_text_p = n_text;
    int r_text_len = strlen(r_text);
    while (*src_p != '\0') {
        if (*src_p == *r_text_p)
            if (is_occurrence(src_p + 1, r_text_p + 1)) {
                while (*n_text_p != '\0')
                    *dest_p++ = *n_text_p++;
                n_text_p = n_text, src_p += r_text_len;
                continue;
            }
        *dest_p++ = *src_p++;
    }
    *dest_p = '\0';
    return dest;
}

char **mem_split(char ***dest, const char *src, const char *delim)
{
    int occur = mem_occurrences(src, delim) + 2;
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

void mem_split_free(char ***dest)
{
    char **dest_p = *dest;
    while (*dest_p != NULL)
        free(*dest_p), dest_p++;
    free(*dest);
}

char *mem_capitalize(char *dest, const char *src, int from_idx, int to_idx)
{
    return dest;
}

int mem_occurrences(const char *src, const char *occurrence)
{
    int i;
    for (i = 0; *src != '\0'; src++)
        if (*src == *occurrence)
            if (is_occurrence(src + 1, occurrence + 1)) ++i;
    return i;
}

char *mem_trim(char *dest, const char *src)
{
    char *dest_p = dest;
    trim_front(src);
    while (*src != '\0') *dest_p++ = *src++; --dest_p;
    trim_back(dest_p); *++dest_p = '\0';
    return dest;
}

char *mem_trim_front(char *dest, const char *src)
{
    char *dest_p = dest;
    trim_front(src);
    while (*src != '\0') *dest_p++ = *src++; *dest_p = '\0';
    return dest;
}

char *mem_trim_back(char *dest, const char *src)
{
    char *dest_p = dest;
    while (*src != '\0') *dest_p++ = *src++; --dest_p;
    trim_back(dest_p); *++dest_p = '\0';
    return dest;
}
