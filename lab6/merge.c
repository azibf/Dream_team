#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>



void Merge_sort(int N, int *pmas)
{
    int *a1 = NULL, *a2 = NULL;
    if ((N / 2) > 1) Merge_sort(N / 2, pmas);
    if ((N - N / 2) > 1) Merge_sort(N - N / 2, (pmas + N / 2));
    a1 = (int *) malloc((N / 2) * sizeof(int));
    a2 = (int *) malloc((N - N / 2) * sizeof(int));
    for (int i = 0; i < N / 2; ++i) a1[i] = *(pmas + i);
    for (int i = 0; i < N - N / 2; ++i) a2[i] = *(pmas + i + N / 2);

    int *p1 = &a1[0], *p2 = &a2[0];
    for (int i = 0; i < N; ++i)
    {
        if (p1 > &a1[N / 2 - 1])
        {
            *(pmas + i) = *p2;
            ++p2;
        }
        else if (p2 > &a2[N - N / 2 - 1])
        {
            *(pmas + i) = *p1;
            ++p1;
        }
        else
        {
            if (*p1 < *p2)
            {
               *(pmas + i) = *p1;
                ++p1;
            }
            else
            {
                *(pmas + i) = *p2;
                ++p2;
            }
        }
    }
    free(a1); free(a2);
}
