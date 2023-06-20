#ifndef _HIGHEST_POW
#define _HIGHEST_POW

#define INT_OFFSET 2

int highestpower(int *array, int arraylen)
{
    for(int bit = 1 << (sizeof(int) * 8) - INT_OFFSET; bit != 0; bit >>= 1)
    {   for(register int i = 0; i < arraylen; i++)
        {   if(array[i] & bit) return bit;
        }
    }

    return 0;
}

#endif