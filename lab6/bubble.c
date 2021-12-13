#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>



void Bubble_sort(int N, int* *pmas)
{
    for (int j = 0; j < N - 1; ++j)
        for (int i = 0; i < N - 1; ++i)
            if (*(pmas + i) > *(pmas + i + 1)) swap((pmas + i), (pmas + i + 1));
}

