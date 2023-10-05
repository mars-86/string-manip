#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str_manip.h"
#include "byte_copy.h"

char **str_split(char *src, const char *delim)
{
    // calculate strlen to allocate the string pointers beforehand so we call malloc once. We add 2 for NULL termination.
    int __dest_len = str_occurrence(src, delim) + 2;
    char **__dest_temp, **__dest;
    char *__token;

    __dest_temp = __dest = (char **)malloc(__dest_len * sizeof(char *));
    if (!__dest_temp) return NULL;

    for(__token = strtok_r(src, delim, &src); __token != NULL; __token = strtok_r(NULL, delim, &src), __dest_temp++)
        *__dest_temp = strndup(__token, strlen(__token));
    *__dest_temp = NULL;

    return __dest;
}

void str_split_free(char **src)
{
    char **__src;
    for (__src = src; *__src != NULL; ++__src)
        free(*__src);
    free(src);
}
