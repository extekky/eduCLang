#include "convert.h"

long convertToBin(long number);
long convertToInt(long number);
int calc(int curPos, int target);

long convertToBin(long number)
{
    long result = 0;
    long place = 1;

    while (number > 0)
    {
        result += (number % 2) * place;
        number /= 2;
        place *= 10;
    }
    return result;
}

long my_pow(long n, long s) {
    if (s == 0)
        return 1;
    if (s == 1)
        return n;
    
    long result = n;
    for (int i = 1; i < s; i++) {
        result *= n;
    }
    
    return result;
}

long convertToInt(long number) {
    long result = 0;
    long place = 0;

    while (number > 0) {
        result += (number % 10) * my_pow(2, place);
        place += 1;
        number /= 10;
    }
    return result;
}

int calc(int curPos, int target)
{
    if (curPos == target)
        return 1;
    if (curPos > target)
        return 0;
    return calc(curPos + 1, target) + calc(curPos + 2, target);
}