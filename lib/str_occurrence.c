#include "str_manip.h"
#include "common.h"

int str_occurrence(const char *src, const char *word)
{
    int __i;
    for (__i = 0; *src != '\0'; src++)
        if (*src == *word)
            if (str_is_match(src + 1, word + 1)) ++__i;
    return __i;
}
