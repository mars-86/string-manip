#include <string.h>
#include "str_manip.h"
#include "common.h"

int str_ends_with(const char *src, const char *text)
{
    return str_ends_with_from(src, text, strlen(src));
}

int str_ends_with_from(const char *src, const char *text, int epos)
{
    char __end = *(src + epos);
    for (src += (epos - strlen(text)); *src != __end && EQU_FWD_CMP(src, text););
    return *text == '\0' && *src == __end ? 1 : 0;
}
