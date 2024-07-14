#include <stdio.h>
#include <stdlib.h>
#include "makeMassive.h"

long **make2dMassive(long row, long col)
{
    long **massive = (long **)calloc(row, sizeof(long *));
    if (massive != NULL)
    {
        for (long i = 0; i < row; i++)
        {
            *(massive + i) = (long *)calloc(col, sizeof(long));
            if (*(massive + i) == NULL)
            {
                printf("Ошибка в выделении памяти!\n");
                exit(2);
            }
        }
    }
    else
    {
        printf("Ошибка в выделении памяти!\n");
        exit(1);
    }
    return massive;
}

void show2DMassive(long **massive, long row, long col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%5ld ", massive[i][j]);
        }
        printf("\n");
    }
}

void free2dMassive(long **massive, long row, short showMassage)
{
    for (long i = 0; i < row; i++)
    {
        free(massive[i]);
    }
    free(massive);

    if (showMassage > 0)
    {
        printf("Memory was cleared\n");
    }
}