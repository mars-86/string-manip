#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str_manip.h"

static inline int str_is_match(const char *src, const char *word)
{
    while (*word != '\0')
        if (*word++ != *src++) return 0;
    return 1;
}

char **str_split(char ***dest, const char *src, const char *delim)
{
    int __occur = str_is_match(src, delim) + 2;
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
