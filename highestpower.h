#include <stdlib.h>

#ifndef _GREATEST_BIT
#define _GREATEST_BIT

#define INT_OFFSET 2

int highestpower(int *array, size_t arraylen)
{
    if(array == NULL || arraylen < 1) return -1;

    for(int bit = 1 << (sizeof(int) * 8) - INT_OFFSET; bit != 0; bit >>= 1)
    {   for(register size_t i = 0; i < arraylen; i++)
        {   if(array[i] & bit) return bit;
        }
    }

    return 0;
}

#endif