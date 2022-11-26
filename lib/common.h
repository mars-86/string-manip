#ifndef _LIB_COMMON_INCLUDED_H_
#define _LIB_COMMON_INCLUDED_H_

static inline int str_is_match(const char *src, const char *word)
{
    while (*word != '\0')
        if (*word++ != *src++) return 0;
    return 1;
}

#endif // _LIB_COMMON_INCLUDED_H_
