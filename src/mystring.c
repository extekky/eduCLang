#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *sliceString(const char *s, int start, int end)
{
        int len = end - start + 1;
        char *substring = (char *)malloc(len + 1);
        if (NULL == substring) {
                free(substring);
                return NULL;
        }
        strncpy(substring, s + start, len);
        substring[len] = '\0';
        return substring;
}

void swap(char *first, char *second)
{
        char temp = *first;
        *first = *second;
        *second = temp;
}

char *reverseString(const char *s)
{
        if (s == NULL) {
                return NULL;
        }

        int length = strlen(s);
        char *reversed = (char *)malloc(length + 1);
        if (reversed == NULL) {
                free(reversed);
                return NULL;
        }
        for (int i = 0; i < length; i++) {
                reversed[i] = s[length - 1 - i];
        }
        reversed[length] = '\0';

        return reversed;
}

// char *longestPalindrome(char *s)
// {
//         char *result = (char *)malloc(10000);
//         if (NULL == result) {
//                 free(result);
//                 return NULL;
//         }
//         result[0] = '\0';
//         int maxLength = 0;

//         for (int i = 0; i < strlen(s); i++) {
//                 for (int j = i; j < strlen(s); j++) {
//                         if (i <= j) {
//                                 char *currentString = sliceString(s, i, j);
//                                 char *reversedString = reverseString(currentString);
//                                 if (NULL == reversedString) {
//                                         return NULL;
//                                 }
//                                 if (strcmp(currentString, reversedString) == 0) {
//                                         if (strlen(currentString) > maxLength) {
//                                                 maxLength = strlen(currentString);
//                                                 strcpy(result, currentString);
//                                         }
//                                 }
//                                 free(currentString);
//                                 free(reversedString);
//                         }
//                 }
//         }
//       f  return result;
// }