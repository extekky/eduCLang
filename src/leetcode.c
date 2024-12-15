#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void swap(char *first, char *second)
{
        char temp = *first;
        *first = *second;
        *second = temp;
}

static void reverseString(char *string) __attribute__((unused));
static void reverseString(char *string)
{
        size_t length = strlen(string);
        for (size_t i = 0; i < (length / 2); i++)
                swap(&string[i], &string[length - 1 - i]);
}

int myAtoi(char *s)
{
        int sign = 1, index = 0;
        while (' ' == s[index])
                index++;

        if ((s[index] == '+' || s[index] == '-' ||
             (s[index] >= '0' && s[index] <= '9')) == 0)
                return 0;
        else if (s[index] == '-' || s[index] == '+')
                sign = (s[index++] == '+') ? 1 : -1;

        int result = 0;
        while (s[index] >= '0' && s[index] <= '9') {
                if (result > INT_MAX / 10 ||
                    (result == INT_MAX / 10 && s[index] - '0' > 7))
                        return sign > 0 ? INT_MAX : INT_MIN;
                result = result * 10 + (s[index++] - '0');
        }
        return result * sign;
}

int reverse(int x)
{
        int sign = x > 0 ? 1 : -1;
        if (-(x / 10) > INT_MAX / 10 ||
            (-(x / 10) == INT_MAX / 10 && -(x % 10) > 7))
                return 0;

        int result = 0;
        x *= sign;
        while (x / 10 != 0 || x % 10 > 0) {
                if (result > INT_MAX / 10 ||
                    (result == INT_MAX / 10 && x % 10 > 2))
                        return 0;
                result = result * 10 + (x % 10);
                x /= 10;
        }
        return result * sign;
}

// char* longestCommonPrefix(char** strs, int strsSize) {
//         char firs_word = strs[0];
//         char *result = (char)malloc(250);
//         strcpy(result, '');
//         for (size_t chr = 0; chr < strlen(firs_word); chr++) {
//                 for (size_t word = 1; word < strsSize; word++) {
//                         if (firs_word[chr] !=  strs[word][chr]) {
//                                 return result;
//                         }
//                 }
//                 strcpy(result, strncpy())
//         }

//         return result;
// }

// static bool isMatch(char *s, char *p) { return 0; }
