#include <stdio.h>
#include "string_manip.h"
#include <string.h>

int main(void)
{
    const char *src = "To be, or not to be, that is the question.";

    printf("%d\n", str_begins_with(src, "To be")); // true
    printf("%d\n", str_begins_with(src, "not to be")); // false
    printf("%d\n", str_begins_with_from(src, "not to be", 10)); //true

    printf("\n%d\n", str_ends_with(src, "question.")); // true
    printf("%d\n", str_ends_with(src, "to be")); // false
    printf("%d\n", str_ends_with_from(src, "to be", 19)); // true

    printf("\n%d\n", str_includes(src, "To be")); // true
    printf("%d\n", str_includes(src, "question")); // true
    printf("%d\n", str_includes(src, "nonexistent")); // false
    printf("%d\n", str_includes_from(src, "To be", 1)); // false
    printf("%d\n", str_includes(src, "TO BE")); // false
}
