#ifndef CONVENIENCE_FUNCTION_H
#define CONVENIENCE_FUNCTION_H

#include <stdlib.h>

void *sliceMemArea(const void *data, 
                   size_t elemSize,  
                   size_t start,     
                   size_t end, 
                   size_t dataLen); // Number of elements in data

#define SLICE_ARRAY(data, elemType, start, end) \
    sliceMemArea(data, sizeof(elemType), start, end, sizeof(data)/sizeof(elemType))

#endif
