#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


void Quick_sort(void* *pmas, int left, int right)
{
    if (left < right)
    {
        void* m = pmas[(right + left) / 2];
        int L_mas = left;
        int R_mas = right;
        do
        {
            while (m > (pmas[L_mas])) ++L_mas;
            while (m < (pmas[R_mas])) --R_mas;
            if (L_mas > R_mas) break;
            swap((L_mas + &pmas[0]), (R_mas + &pmas[0]));
            ++L_mas; --R_mas;
        } while (R_mas > L_mas);
        Quick_sort(pmas, left, R_mas);
        Quick_sort(pmas , L_mas, right);
    }
}
