#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leetcode.h"
#include "lib_of_books.h"
#include "makeMassive.h"
#include "mystring.h"

int main(void)
{
        char *strs[] = {"f", "fl", "floght"};
        printf("%s\n", longestCommonPrefix(strs, 3));
        return 0;
}
