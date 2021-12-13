#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>



void Merge_sort(int N, int *pmas)
{
    int *a1 = NULL, *a2 = NULL;
    int c1 = 1, c2 = 0;
    a1 = (int *) malloc(c1 * sizeof(void*));
    a2 = (int *) malloc(c2 * sizeof(void*));
    a1[0] = *pmas;
    for (int i = 1; i < N; ++i)
    {
        if (*(pmas + i) > *(pmas + i - 1))
        {
            ++c1;
            a1 = (int *) realloc(a1, c1 * sizeof(void*));
            a1[c1 - 1] = *(pmas + i);
        }
        else
        {
            ++c2;
            a2 = (int *) realloc(a2, c2 * sizeof(void*));
            a2[c2 - 1] = *(pmas + i);
        }
    }
    int *p1 = &a1[0], *p2 = &a2[0];
    for (int i = 0; i < N; ++i)
    {
        if (p1 > &a1[c1 - 1])
        {
            *(pmas + i) = *p2;
            ++p2;
        }
        else if (p2 > &a2[c2 - 1])
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
