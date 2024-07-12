#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convert.h"

enum
{
    max_lengh_name = 50
};

struct person
{
    short age, high;
    char *first_name, *middle_name, *last_name;
};

int main()
{
    struct person stas;

    stas.age = 20;
    stas.high = 189;

    stas.first_name = "Stas";
    stas.middle_name = "Stepanov";
    stas.last_name = "Eduardovich";

    printf("Длинна фамилии: %ld\n", strlen(stas.middle_name));
    printf("Размер структуры Person: %ld\n", sizeof(struct person));
    printf("Размер first_name: %ld\n", sizeof(stas.middle_name));
    // printf("Фамилия%s: %s\n", stas.first_name, stas.middle_name);
    printf("Отчество %s: %s\n", stas.first_name, stas.last_name);
    printf("Возраст %s:%d\n", stas.first_name, stas.age);

    return 0;
}