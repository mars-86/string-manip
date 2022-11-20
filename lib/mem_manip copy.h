#ifndef _LIB_MEM_MANIP_INCLUDED_H_
#define _LIB_MEM_MANIP_INCLUDED_H_

char *str_replace(char *dest, const char *src, const char *r_text, const char *n_text);
char **str_split(char ***dest, const char *src, const char *delim);
void str_split_free(char ***dest);
const char *str_capitalize(char *dest, const char *src, int from_idx, int to_idx);
int str_occurrences(const char *src, const char *occurrence);

#endif // _LIB_MEM_MANIP_INCLUDED_H_
