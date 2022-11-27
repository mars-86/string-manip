#include "str_manip.h"

int str_includes(const char *__restrict src, const char *__restrict text)
{
    const char *__text;
    for (__text = text; *src != '\0'; ++src) {
        if (*src == *__text) {
            for(++src, ++__text; *src == *__text; ++src, ++__text);
            if (*__text == '\0') return 1;
            __text = text;
        }
    }
    return 0;
}

int str_includes_from(const char *__restrict src, const char *__restrict text, int bpos)
{
    return str_includes(src + bpos, text);
}
