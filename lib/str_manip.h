#ifndef _LIB_STR_MANIP_INCLUDED_H_
#define _LIB_STR_MANIP_INCLUDED_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* replace RTEXT existing in SRC for NTEXT to DEST */
extern char * __cdecl str_replace(char *__restrict __dest, const char *__restrict __src, const char *__restrict __rtext, const char *__restrict __ntext)
    __MINGW_NOTHROW __MINGW_ATTRIB_NONNULL(1) __MINGW_ATTRIB_NONNULL(2) __MINGW_ATTRIB_NONNULL(3) __MINGW_ATTRIB_NONNULL(4);

/* split SRC according to DELIM to DEST */
extern char **__cdecl str_split(char ***__restrict __dest, const char *__restrict __src, const char *__restrict __delim)
    __MINGW_NOTHROW __MINGW_ATTRIB_NONNULL(1) __MINGW_ATTRIB_NONNULL(2) __MINGW_ATTRIB_NONNULL(3);

/* free SRC created previously with strsplit */
extern void __cdecl str_split_free(char ***__src)
    __MINGW_NOTHROW;

/* to lower case SRC to DEST */
extern char * __cdecl str_lowerc(char *__restrict __dest, const char *__restrict __src)
    __MINGW_NOTHROW __MINGW_ATTRIB_NONNULL(1) __MINGW_ATTRIB_NONNULL(2);

/* to lower case no more than N characters of SRC to DEST */
extern char * __cdecl strn_lowerc(char *__restrict __dest, const char *__restrict __src, size_t __n)
    __MINGW_NOTHROW __MINGW_ATTRIB_NONNULL(1) __MINGW_ATTRIB_NONNULL(2);

/* to upper case SRC to DEST */
extern char * __cdecl str_upperc(char *__restrict __dest, const char *__restrict __src)
    __MINGW_NOTHROW __MINGW_ATTRIB_NONNULL(1) __MINGW_ATTRIB_NONNULL(2);

/* to upper case no more than N characters of SRC to DEST */
extern char * __cdecl strn_upperc(char *__restrict __dest, const char *__restrict __src, size_t __n)
    __MINGW_NOTHROW __MINGW_ATTRIB_NONNULL(1) __MINGW_ATTRIB_NONNULL(2);

/* count OCCURRENCE ocurrences within SRC */
extern int __cdecl str_occ(const char *__restrict __src, const char *__restrict __occurrence)
    __MINGW_NOTHROW __MINGW_ATTRIB_NONNULL(1) __MINGW_ATTRIB_NONNULL(2);

/* trim SRC to DEST */
extern char * __cdecl str_trim(char *__restrict __dest, const char *__restrict __src)
    __MINGW_NOTHROW __MINGW_ATTRIB_NONNULL(1) __MINGW_ATTRIB_NONNULL(2);

/* trim SRC front to DEST */
extern char * __cdecl str_trimf(char *__restrict __dest, const char *__restrict __src)
    __MINGW_NOTHROW __MINGW_ATTRIB_NONNULL(1) __MINGW_ATTRIB_NONNULL(2);

/* trim SRC back to DEST */
extern char * __cdecl str_trimb(char *__restrict __dest, const char *__restrict __src)
    __MINGW_NOTHROW __MINGW_ATTRIB_NONNULL(1) __MINGW_ATTRIB_NONNULL(2);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // _LIB_STR_MANIP_INCLUDED_H_
