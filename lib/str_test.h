#ifndef _LIB_STR_TEST_INCLUDED_H_
#define _LIB_STR_TEST_INCLUDED_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* checks if SRC starts with TEXT */
extern int __cdecl str_begins_with(const char *__restrict __src, const char *__restrict __text)
    __MINGW_NOTHROW __MINGW_ATTRIB_NONNULL(1) __MINGW_ATTRIB_NONNULL(2);

/* checks if SRC starts with TEXT setting start position */
extern int __cdecl str_begins_with_from(const char *__restrict __src, const char *__restrict __text, int __bpos)
    __MINGW_NOTHROW __MINGW_ATTRIB_NONNULL(1) __MINGW_ATTRIB_NONNULL(2);

/* checks if SRC ends with TEXT */
extern int __cdecl str_ends_with(const char *__restrict __src, const char *__restrict __text)
    __MINGW_NOTHROW __MINGW_ATTRIB_NONNULL(1) __MINGW_ATTRIB_NONNULL(2);

/* checks if SRC ends with TEXT setting end position */
extern int __cdecl str_ends_with_from(const char *__restrict __src, const char *__restrict __text, int __epos)
    __MINGW_NOTHROW __MINGW_ATTRIB_NONNULL(1) __MINGW_ATTRIB_NONNULL(2);

/* checks if SRC includes TEXT */
extern int __cdecl str_includes(const char *__restrict __src, const char *__restrict __text)
    __MINGW_NOTHROW __MINGW_ATTRIB_NONNULL(1) __MINGW_ATTRIB_NONNULL(2);

/* checks if SRC includes TEXT setting start position */
extern int __cdecl str_includes_from(const char *__restrict __src, const char *__restrict __text, int __bpos)
    __MINGW_NOTHROW __MINGW_ATTRIB_NONNULL(1) __MINGW_ATTRIB_NONNULL(2);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // _LIB_STR_TEST_INCLUDED_H_
