#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>



void Insertion_sort(int N, int *pmas)
{
    int *a;
    for (int i = 1; i < N; ++i)
    {
        a = pmas + i;
        for (int j = i - 1; j >= 0; --j)
        {
            if (*a >= *(pmas + j)) break;
            swap(a, (pmas + j));
            --a;
        }
    }
}
