#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "convenience_function.h"
#include "leetcode.h"
#include "lib_of_books.h"
#include "linked_list.h"
#include "makeMassive.h"
#include "mystring.h"

#define BUFFER_SIZE 512
#define MAX_NUMBERS 100

int main()
{
        int *numbers = malloc(MAX_NUMBERS * sizeof(int));
        if (numbers == NULL) {
                perror("Memory allocation failed for numbers");
                return EXIT_FAILURE;
        }

        FILE *file = fopen("/home/stas/projects/c/eduCLang/file.txt", "r");
        if (file == NULL) {
                perror("Error opening file");
                free(numbers);
                return EXIT_FAILURE;
        }

        char *buffer = malloc(BUFFER_SIZE);
        if (buffer == NULL) {
                perror("Memory allocation failed for buffer");
                fclose(file);
                free(numbers);
                return EXIT_FAILURE;
        }

        size_t index = 0;
        int ch;
        while ((ch = fgetc(file)) != EOF && index < BUFFER_SIZE - 1) {
                buffer[index++] = (char)ch;
        }
        buffer[index] = '\0';

        fclose(file);

        char **tokens = sliceStringBySymbol(buffer, ' ');
        free(buffer);

        if (tokens == NULL) {
                perror("Error slicing string");
                free(numbers);
                return EXIT_FAILURE;
        }

        size_t count = 0;
        for (size_t i = 0; tokens[i] != NULL && count < MAX_NUMBERS; i++) {
                numbers[count++] = myAtoi(tokens[i]);
        }

        for (size_t i = 0; tokens[i] != NULL; i++) {
                free(tokens[i]);
        }
        free(tokens);

        int sum = 0;
        for (size_t i = 0; i < count; i++) {
                sum += numbers[i];
        }

        printf("%d", sum);

        free(numbers);
        return EXIT_SUCCESS;
}
