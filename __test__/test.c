#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../lib/str_manip.h"

int main(void)
{
    const char *s1 = "To be, or not to be, that is the question.";

    assert(str_begins_with(s1, "To be") == 1); // true
    assert(str_begins_with(s1, "not to be") == 0); // false
    assert(str_begins_with_from(s1, "not to be", 10) == 1); // true

    assert(str_ends_with(s1, "question.") == 1); // true
    assert(str_ends_with(s1, "to be") == 0); // false
    assert(str_ends_with_from(s1, "to be", 19) == 1); // true

    assert(str_includes(s1, "To be") == 1); // true
    assert(str_includes(s1, "question") == 1); // true
    assert(str_includes(s1, "nonexistent") == 0); // false
    assert(str_includes_from(s1, "To be", 1) == 0); // false
    assert(str_includes(s1, "TO BE") == 0); // false

    const char *s2 = "abc";
    char s3[] = "To be, or not to be, that is the question.";
    const char s3_res[][10] = {{"To"}, {"be,"}, {"or"}, {"not"}, {"to"}, {"be,"}, {"that"}, {"is"}, {"the"}, {"question."}};
    char dest[128], dest2[128];

    char **s3_split = str_split(s3, " ");
    assert(s3_split != NULL);

    int i;
    for (i = 0; s3_split[i] != NULL; ++i) {
        if (strcmp(s3_split[i], s3_res[i]) != 0) {
            str_split_free(s3_split);
            printf("assertion failed at index: %d\n", i);
            assert(-1 == i);
        }
    }
    str_split_free(s3_split);

    assert(strcmp(str_pad_front(dest, s2, " ", 10), "       abc") == 0); // "       abc"
    assert(strcmp(str_pad_front(dest, s2, "foo", 10), "foofoofabc") == 0); // "foofoofabc"
    assert(strcmp(str_pad_front(dest, s2, "123465", 6), "123abc") == 0); // "123abc"
    assert(strcmp(str_pad_front(dest, s2, "0", 8), "00000abc") == 0); // "00000abc"
    assert(strcmp(str_pad_front(dest, s2, " ", 1), "abc") == 0); // "abc"

    assert(strcmp(str_pad_back(dest, s2, " ", 10), "abc       ") == 0); // "abc       "
    assert(strcmp(str_pad_back(dest, s2, "foo", 10), "abcfoofoof") == 0); // "abcfoofoof"
    assert(strcmp(str_pad_back(dest, s2, "123456", 6), "abc123") == 0); // "abc123"
    assert(strcmp(str_pad_back(dest, s2, " ", 1), "abc") == 0); // "abc"

    assert(strcmp(str_replace(dest, s1, "be", "code"), "To code, or not to code, that is the question.") == 0);
    assert(strcmp(str_replace(dest2, dest, "question", "matter"), "To code, or not to code, that is the matter.") == 0);

    assert(str_char_at(s1, 43) == 'T');
    assert(str_char_code_at(s1, 10) == 110);

    assert(strcmp(str_uppercase(dest, s2), "ABC") == 0);
    assert(strcmp(str_lowercase(dest, "ABc"), "abc") == 0);

    assert(strcmp(str_remove_char(dest, s1, ' '), "Tobe,ornottobe,thatisthequestion.") == 0);
    assert(strcmp(str_remove_char(dest, s1, ','), "To be or not to be that is the question.") == 0);
}
