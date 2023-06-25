void binswap(int *array, int arraylen, int cmpbit)
{
    while(arraylen > 1 && cmpbit != 0)
    {   register int dst = arraylen - 1, src = 0;

        start:
        while(((array[dst] & cmpbit) != 0) && dst != 0) dst--;
        while(((array[src] & cmpbit) == 0) && src <= dst) src++;

        if(src < dst)
        {   int temp = array[dst];
            array[dst] = array[src];
            array[src] = temp;

            goto start;
        }

        cmpbit >>= 1;

        if(src != 0)
        {   binswap(&array[src], arraylen - src, cmpbit);
            arraylen = src;
        }
    }

    return;
} 