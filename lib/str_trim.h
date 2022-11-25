#ifndef _LIB_STR_TRIM_INCLUDED_H_
#define _LIB_STR_TRIM_INCLUDED_H_

#define TRIM_TEST_N(src) src != ' ' && src != '\n' && src != '\t'
#define TRIM_TEST(src) src == ' ' || src == '\n' || src == '\t'

#define TRIM_FRONT(src) while (TRIM_TEST(*src)) ++src
#define TRIM_BACK(src) while (TRIM_TEST(*src)) --src

#endif // _LIB_STR_TRIM_INCLUDED_H_
