#include <stdio.h>
#include "string_manip.h"
#include <string.h>

int main(void)
{
    const char *s1 = "To be, or not to be, that is the question.";

    printf("%d\n", str_begins_with(s1, "To be")); // true
    printf("%d\n", str_begins_with(s1, "not to be")); // false
    printf("%d\n", str_begins_with_from(s1, "not to be", 10)); //true

    printf("\n%d\n", str_ends_with(s1, "question.")); // true
    printf("%d\n", str_ends_with(s1, "to be")); // false
    printf("%d\n", str_ends_with_from(s1, "to be", 19)); // true

    printf("\n%d\n", str_includes(s1, "To be")); // true
    printf("%d\n", str_includes(s1, "question")); // true
    printf("%d\n", str_includes(s1, "nonexistent")); // false
    printf("%d\n", str_includes_from(s1, "To be", 1)); // false
    printf("%d\n", str_includes(s1, "TO BE")); // false

    const char *src2 = "abc";
    char dest[128];

    printf("\n%s\n", str_pad_front(dest, src2, " ", 10)); // "       abc"
    printf("%s\n", str_pad_front(dest, src2, "foo", 10)); // "foofoofabc"
    printf("%s\n", str_pad_front(dest, src2, "123465", 6)); // "123abc"
    printf("%s\n", str_pad_front(dest, src2, "0", 8)); // "00000abc"
    printf("%s\n", str_pad_front(dest, src2, " ", 1)); // "abc"

    printf("\n%s\n", str_pad_back(dest, src2, " ", 10)); // "abc       "
    printf("%s\n", str_pad_back(dest, src2, "foo", 10)); // "abcfoofoof"
    printf("%s\n", str_pad_back(dest, src2, "123456", 6)); // "abc123"
    printf("%s\n", str_pad_back(dest, src2, " ", 1)); // "abc"
}
