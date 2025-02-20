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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **sliceStringBySymbol(const char *s, char symbol)
{
        if (!s)
                return NULL;

        int max_words = 10;
        int max_word_len = 100;
        char **words = malloc(max_words * sizeof(char *));
        if (!words) {
                perror("Memory allocation failed!");
                return NULL;
        }

        int word_count = 0;
        int word_len = 0;

        words[word_count] = malloc(max_word_len);
        if (!words[word_count]) {
                perror("Memory allocation failed!");
                free(words);
                return NULL;
        }

        for (size_t i = 0; i < strlen(s); i++) {
                if (s[i] == symbol) {
                        if (word_len == 0)
                                continue;
                        words[word_count][word_len] = '\0';
                        word_count++;
                        word_len = 0;

                        if (word_count >= max_words) {
                                max_words *= 2;
                                char **temp =
                                    realloc(words, max_words * sizeof(char *));
                                if (!temp) {
                                        perror("Memory allocation failed!");
                                        goto cleanup;
                                }
                                words = temp;
                        }

                        words[word_count] = malloc(max_word_len);
                        if (!words[word_count]) {
                                perror("Memory allocation error");
                                goto cleanup;
                        }
                        continue;
                }

                if (word_len >= max_word_len - 1) {
                        continue;
                }

                words[word_count][word_len++] = s[i];
        }

        if (word_len == 0 && word_count > 0) {
                free(words[word_count]);
                words[word_count] = NULL;
        } else {
                words[word_count][word_len] = '\0';
                words[++word_count] = NULL;
        }

        return words;

cleanup:
        for (int i = 0; i <= word_count; i++) {
                free(words[i]);
        }
        free(words);
        return NULL;
}