#ifndef __LIB_COMMON_INCLUDED_H__
#define __LIB_COMMON_INCLUDED_H__

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

#endif // __LIB_COMMON_INCLUDED_H__
