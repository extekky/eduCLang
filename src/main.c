#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "convenience_function.h"
#include "leetcode.h"
#include "lib_of_books.h"
#include "makeMassive.h"
#include "mystring.h"

#define PRINT_INT(number) (printf("%d\n", (number)))
#define PRINT_POINT(point) (printf("x = %d, y = %.1f\n", (point).x, (point).y))
#define PRINT_STR(string) (printf("%s\n", (string)))

int main(void)
{
        int numbers[] = {10, 20, 30, 40, 50};
        int *sub = SLICE_ARRAY(numbers, int, 0, 3);

        if (sub) {
                for (size_t i = 0; i < (3 - 0); i++) {
                        PRINT_INT(sub[i]);
                }
                free(sub);
        } else
                return 1;

        typedef struct {
                int x;
                double y;
        } Point;

        Point points[] = {{1, 2.5}, {3, 4.5}, {5, 6.5}};
        Point *slice = SLICE_ARRAY(points, Point, 0, 3);

        if (slice) {
                for (size_t i = 0; i < (3 - 0); i++) {
                        PRINT_POINT(slice[i]);
                }
                free(slice);
        } else
                return 2;

        const char str[] = "Hello, World!\n";
        char *sub_str = SLICE_ARRAY(str, char, 7, 12);

        if (sub_str) {
                PRINT_STR(sub_str);
                free(sub_str);
        } else
                return 3;

        return 0;
}
