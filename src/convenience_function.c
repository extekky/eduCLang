#include <stdlib.h>
#include <string.h>

#define VALID_PARAMS(data, elemSize, start, end, dataLen) \
    ((data) != NULL && (elemSize) != 0 && (start) < (end) && (end) <= (dataLen))

#define SRC_OFFSET(data, start, elemSize) ((const char *)(data) + (start) * (elemSize))

#define CHECK_SIZE_OVERFLOW(numElem, elemSize) ((numElem) >  (size_t) - 1 / (elemSize)) 

// Удобный вызов для массивов (только для статических массивов!)
#define SLICE_ARRAY(data, elemType, start, end) \
    sliceMemArea(data, sizeof(elemType), start, end, sizeof(data)/sizeof(elemType))

void *sliceMemArea(const void *data, size_t elemSize, size_t start, size_t end, size_t dataLen) {
    if (!VALID_PARAMS(data, elemSize, start, end, dataLen)) {
        return NULL;
    }

    size_t numElem = end - start;
    
    if (CHECK_SIZE_OVERFLOW(numElem, elemSize)) {
        return NULL;
    }

    size_t totalSliceLen = numElem * elemSize;
    void *slice = malloc(totalSliceLen);
    
    if (!slice) {
        return NULL;
    }

    memcpy(slice, SRC_OFFSET(data, start, elemSize), totalSliceLen);
    return slice;
}