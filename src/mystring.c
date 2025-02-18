#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *sliceString(char const *string, int start, int end)
{
        int len = end - start + 1;
        char *substring = (char *)malloc(len + 1);
        if (NULL == substring) {
                free(substring);
                return NULL;
        }
        strncpy(substring, string + start, len);
        substring[len] = '\0';
        return substring;
}

void swap(char *first, char *second)
{
        char temp = *first;
        *first = *second;
        *second = temp;
}

char *reverseString(char *s)
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