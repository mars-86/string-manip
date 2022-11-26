#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str_manip.h"
#include "common.h"

static inline int str_isocc(const char *src, const char *word)
{
    while (*word != '\0')
        if (*word++ != *src++) return 0;
    return 1;
}

int str_occurrence(const char *src, const char *word)
{
    int __i;
    for (__i = 0; *src != '\0'; src++)
        if (*src == *word)
            if (str_isocc(src + 1, word + 1)) ++__i;
    return __i;
}
