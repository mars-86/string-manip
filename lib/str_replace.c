#include <stdio.h>
#include <string.h>
#include "str_manip.h"
#include "common.h"

char *str_replace(char *dest, const char *src, const char *rtext, const char *ntext)
{
    char *__dest = dest;
    const char *__src = src, *__rtext = rtext, *__ntext = ntext;
    size_t r_text_len = strlen(rtext);
    while (*__src != '\0') {
        if (*__src == *__rtext)
            if (str_is_match(__src + 1, __rtext + 1)) {
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
