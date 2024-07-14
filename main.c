#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "makeMassive.h"

int main(void)
{
    long row = 3, col = 4;
    
    // Создание массива
    long **myMassive = make2dMassive(row, col);

    // Вывод масства
    show2DMassive(myMassive, row, col);

    // Очиска памяти
    free2dMassive(myMassive, row, 0);

    return 0;
}

/*
 int count = 0;

    // Make 2D masive:
    int **p = (int **)malloc(3 * sizeof(int *));
    if (p == NULL)
    {
        printf("Не удалось выделить память для **p :(\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            *(p + i) = (int *)malloc(2 * sizeof(int));
            if (*(p + i) == NULL)
            {
                printf("Не удалось выделить память для *(p + %d) :(\n", i);
                return 1;
            }
            else
            {
                for (int j = 0; j < 2; j++)
                {
                    *(*(p + i) + j) = count;
                    count++;
                }
            }
        }
    }
    // Read 2D masiive:
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }

    // Clear memory:
    for (int i = 0; i < 3; i++)
    {
        free(*(p + i));
    }
    free(p);
*/