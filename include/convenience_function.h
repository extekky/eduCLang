#ifndef CONVENIENCE_FUNCTION_H
#define CONVENIENCE_FUNCTION_H

#include <stdlib.h>

void *sliceMemArea(const void *data, // Указатель на данные любого типа
                   size_t elemSize,  // Размер одного элемента данных (в байтах)
                   size_t start,     // Начальный индекс (в элементах)
                   size_t end, // Конечный индекс (в элементах, включительно)
                   size_t dataLen); // Количество элементов в data

#define SLICE_ARRAY(data, elemType, start, end) \
    sliceMemArea(data, sizeof(elemType), start, end, sizeof(data)/sizeof(elemType))

#endif
