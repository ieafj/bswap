#include <stdlib.h>
#include <string.h>

int radixsort(int *array, int arraysize, int highestpower)
{
    if(array == NULL || arraysize < 1) return -1;

    int buffer[arraysize];

    if(highestpower != 0)
    {   for(int power = 1; power <= highestpower; power <<= 1)
        {   register int zeroes = 0, ones = 0;

            for(register int i = 0; i < arraysize; i++)
            {   if(array[i] & power) buffer[ones++] = array[i];
                else array[zeroes++] = array[i];
            }

            if(ones) memcpy(&array[zeroes], buffer, sizeof(int) * ones);
        }
    }

    return 0;
}