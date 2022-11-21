#include <stdio.h>
#include "string_manip.h"
#include <string.h>

int main(void)
{
    char src[64] = "        Hello, world!    \t", dest[64];

    strtrim(dest, src);
    printf("%s\n", src);
    printf("%s\n", dest);
    strncap(dest, dest, 3);
    printf("%s\n", dest);
}
