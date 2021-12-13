#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>



void Shell_sort(int N, int *pmas)
{
    int *a;
    int d = N/2;
    while (d != 0)
    {
        for (int i = d; i < N; ++i)
        {
            a = pmas + i;
            for (int j = i - d; j >= 0; j -= d)
            {
                if (*a >= *(pmas + j)) break;
                swap(a, (pmas + j));
                --a;
            }
        }
        d /= 2;
    }
}


void Shell_sort_float(int N, float *pmas)
{
    int *a;
    int d = N/2;
    while (d != 0)
    {
        for (int i = d; i < N; ++i)
        {
            a = pmas + i;
            for (int j = i - d; j >= 0; j -= d)
            {
                if (*a >= *(pmas + j)) break;
                swap(a, (pmas + j));
                --a;
            }
        }
        d /= 2;
    }
}
