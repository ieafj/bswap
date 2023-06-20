#include <stdlib.h>

int binswap(int *array, int arraylen, int maxbit)
{
    if(array == NULL || arraylen < 1) return -1;
    if(arraylen < 2) return 0;

    while(maxbit != 0)
    {   register int moved = 0;

        for(register int src = 0; src < arraylen - moved;)
        {   if(array[src] & maxbit)
            {   int dst = (arraylen - 1) - moved, temp = array[dst];
                array[dst] = array[src];
                array[src] = temp;
                moved++;
            }
            else src++;
        }

        maxbit >>= 1;

        if(moved > 0)
        {   arraylen -= moved;
            binswap(&array[arraylen], moved, maxbit);
        }
    }

    return 0;
}