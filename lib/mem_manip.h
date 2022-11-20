#ifndef _LIB_MEM_MANIP_INCLUDED_H_
#define _LIB_MEM_MANIP_INCLUDED_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern char * __cdecl mem_replace(char *dest, const char *src, const char *r_text, const char *n_text);
extern char **__cdecl mem_split(char ***dest, const char *src, const char *delim);
extern void __cdecl mem_split_free(char ***dest);
extern char * __cdecl mem_capitalize(char *dest, const char *src, int from_idx, int to_idx);
extern int __cdecl mem_occurrences(const char *src, const char *occurrence);
extern char * __cdecl mem_trim(char *dest, const char *src);
extern char * __cdecl mem_trim_front(char *dest, const char *src);
extern char * __cdecl mem_trim_back(char *dest, const char *src);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // _LIB_MEM_MANIP_INCLUDED_H_
