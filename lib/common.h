#ifndef _LIB_COMMON_INCLUDED_H_
#define _LIB_COMMON_INCLUDED_H_

#define DIF_FWD_CMP(s1, s2) (*s1++ != *s2++)
#define EQU_FWD_CMP(s1, s2) (*s1++ == *s2++)

#define DIF_BCK_CMP(s1, s2) (*s1-- != *s2--)
#define EQU_BCK_CMP(s1, s2) (*s1-- == *s2--)

static inline int str_is_match(const char *src, const char *word)
{
    while (*word != '\0')
        if (*word++ != *src++) return 0;
    return 1;
}

#endif // _LIB_COMMON_INCLUDED_H_
