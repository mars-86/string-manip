#include <string.h>
#include "str_test.h"

#define DIF_FWD_CMP(s1, s2) (*s1++ != *s2++)
#define EQU_FWD_CMP(s1, s2) (*s1++ == *s2++)

#define DIF_BCK_CMP(s1, s2) (*s1-- != *s2--)
#define EQU_BCK_CMP(s1, s2) (*s1-- == *s2--)

#define TEST_STR_POS(s, pos) (pos < 0 || pos > (strlen(s)))

int str_begins_with(const char *src, const char *text)
{
    while (*text != '\0' && EQU_FWD_CMP(src, text));
    return *text == '\0' ? 1 : 0;
}

int str_begins_with_from(const char *src, const char *text, int bpos)
{
    if (TEST_STR_POS(src, bpos)) return 0;
    return str_begins_with(src + bpos, text);
}

int str_ends_with(const char *src, const char *text)
{
    return str_ends_with_from(src, text, strlen(src));
}

int str_ends_with_from(const char *src, const char *text, int epos)
{
    if (TEST_STR_POS(src, epos)) return 0;
    char __end = *(src + epos);
    for (src += (epos - strlen(text)); *src != __end && EQU_FWD_CMP(src, text););
    return *text == '\0' && *src == __end ? 1 : 0;
}

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
    if (TEST_STR_POS(src, bpos)) return 0;
    return str_includes(src + bpos, text);
}
