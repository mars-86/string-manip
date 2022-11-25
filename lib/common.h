#ifndef _LIB_COMMON_INCLUDED_H_
#define _LIB_COMMON_INCLUDED_H_

#define TRIM_TEST_N(src) src != ' ' && src != '\n' && src != '\t'
#define TRIM_TEST(src) src == ' ' || src == '\n' || src == '\t'

#define TRIM_FRONT(src) while (trim_test(*src)) ++src
#define TRIM_BACK(src) while (trim_test(*src)) --src

#endif // _LIB_COMMON_INCLUDED_H_
