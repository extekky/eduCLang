#ifndef MAKEMASSIVE_H
#define MAKEMASSIVE_H

// Создание массива
long **make2dMassive(long col, long row);

// Вывод масства
void show2DMassive(long **massive, long row, long col);

// Очиска памяти
void free2dMassive(long **massive, long row, short showMassage);

#endif