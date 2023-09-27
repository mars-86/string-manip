#ifndef _LIB_LINUX_PROTO_INCLUDED_H_
#define _LIB_LINUX_PROTO_INCLUDED_H_

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* replace RTEXT existing in SRC for NTEXT to DEST */
extern char * __attribute__((cdecl)) str_replace(char *__restrict __dest, const char *__restrict __src, const char *__restrict __rtext, const char *__restrict __ntext)
    __attribute__((nothrow)) __attribute__((1, 2, 3, 4));

/* split SRC according to DELIM to DEST */
extern char ** __attribute__((cdecl)) str_split(char ***__restrict __dest, const char *__restrict __src, const char *__restrict __delim)
    __attribute__((nothrow)) __attribute__((1, 2, 3));

/* free SRC created previously with str_split */
extern void __attribute__((cdecl)) str_split_free(char ***__src)
    __attribute__((nothrow)) __attribute__((1));

/* to lower case SRC to DEST */
extern char * __attribute__((cdecl)) str_lowercase(char *__restrict __dest, const char *__restrict __src)
    __attribute__((nothrow)) __attribute__((1, 2));

/* to lower case no more than N characters of SRC to DEST */
extern char * __attribute__((cdecl)) strn_lowercase(char *__restrict __dest, const char *__restrict __src, size_t __n)
    __attribute__((nothrow)) __attribute__((1, 2));

/* to upper case SRC to DEST */
extern char * __attribute__((cdecl)) str_uppercase(char *__restrict __dest, const char *__restrict __src)
    __attribute__((nothrow)) __attribute__((1, 2));

/* to upper case no more than N characters of SRC to DEST */
extern char * __attribute__((cdecl)) strn_uppercase(char *__restrict __dest, const char *__restrict __src, size_t __n)
    __attribute__((nothrow)) __attribute__((1, 2));

/* count WORD ocurrence within SRC */
extern int __attribute__((cdecl)) str_occurrence(const char *__restrict __src, const char *__restrict __word)
    __attribute__((nothrow)) __attribute__((1, 2));

/* trim SRC to DEST */
extern char * __attribute__((cdecl)) str_trim(char *__restrict __dest, const char *__restrict __src)
    __attribute__((nothrow)) __attribute__((1, 2));

/* trim SRC front to DEST */
extern char * __attribute__((cdecl)) str_trim_front(char *__restrict __dest, const char *__restrict __src)
    __attribute__((nothrow)) __attribute__((1, 2));

/* trim SRC back to DEST */
extern char * __attribute__((cdecl)) str_trim_back(char *__restrict __dest, const char *__restrict __src)
    __attribute__((nothrow)) __attribute__((1, 2));

/* remove char from SRC back to DEST */
extern char * __attribute__((cdecl)) str_remove_char(char *__restrict __dest, const char *__restrict __src, const char c)
    __attribute__((nothrow)) __attribute__((1, 2));

/* pad SRC's front PADDING times with PTEXT */
extern char *__attribute__((cdecl)) str_pad_front(char *__restrict __dest, const char *__restrict __src, const char *__restrict __ptext, int __padding)
    __attribute__((nothrow)) __attribute__((1, 2));

/* pad SRC's back PADDING times with PTEXT */
extern char *__attribute__((cdecl)) str_pad_back(char *__restrict __dest, const char *__restrict __src, const char *__restrict __ptext, int __padding)
    __attribute__((nothrow)) __attribute__((1, 2));

/* return SRC char at IDX position */
extern char __attribute__((cdecl)) str_char_at(const char *__src, size_t __idx)
    __attribute__((nothrow)) __attribute__((1));

/* return SRC char code at IDX position */
extern int __attribute__((cdecl)) str_char_code_at(const char *__src, size_t __idx)
    __attribute__((nothrow)) __attribute__((1));

/* TEST FUNCTIONS */

/* checks if SRC starts with TEXT */
extern int __attribute__((cdecl)) str_begins_with(const char *__restrict __src, const char *__restrict __text)
    __attribute__((nothrow)) __attribute__((1, 2));

/* checks if SRC starts with TEXT setting start position */
extern int __attribute__((cdecl)) str_begins_with_from(const char *__restrict __src, const char *__restrict __text, int __bpos)
    __attribute__((nothrow)) __attribute__((1, 2));

/* checks if SRC ends with TEXT */
extern int __attribute__((cdecl)) str_ends_with(const char *__restrict __src, const char *__restrict __text)
    __attribute__((nothrow)) __attribute__((1, 2));

/* checks if SRC ends with TEXT setting end position */
extern int __attribute__((cdecl)) str_ends_with_from(const char *__restrict __src, const char *__restrict __text, int __epos)
    __attribute__((nothrow)) __attribute__((1, 2));

/* checks if SRC includes TEXT */
extern int __attribute__((cdecl)) str_includes(const char *__restrict __src, const char *__restrict __text)
    __attribute__((nothrow)) __attribute__((1, 2));

/* checks if SRC includes TEXT setting start position */
extern int __attribute__((cdecl)) str_includes_from(const char *__restrict __src, const char *__restrict __text, int __bpos)
    __attribute__((nothrow)) __attribute__((1, 2));

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // _LIB_LINUX_PROTO_INCLUDED_H_
