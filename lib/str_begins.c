#include <string.h>
#include "str_manip.h"
#include "common.h"

int str_begins_with(const char *src, const char *text)
{
    while (*text != '\0' && EQU_FWD_CMP(src, text));
    return *text == '\0' ? 1 : 0;
}

int str_begins_with_from(const char *src, const char *text, int bpos)
{
    return str_begins_with(src + bpos, text);
}
