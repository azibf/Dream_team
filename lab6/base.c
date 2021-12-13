#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


void out(int N, int *pmas)
{

    for (int i = 0; i < N; ++i) printf("%d ", *(pmas + i));
    printf("\n");
}

void fill_int(int N, int *pmas)
{
    do for (int i = 0; i < N; ++i) *(pmas + i) = rand() - 16320;
    while(check_sort(N, pmas) == 1);
}

void fill_uns_long(int N, int *pmas)
{
    do for (int i = 0; i < N; ++i) *(pmas + i) = (unsigned long)(rand() * rand());
    while(check_sort(N, pmas) == 1);
}

void fill_s_short(int N, int *pmas)
{
    do for (int i = 0; i < N; ++i) *(pmas + i) = (signed short)(pow(-1, rand()) * (rand() % 16384));
    while(check_sort(N, pmas) == 1);
}

void fill_float(int N, int *pmas)
{
    do for (int i = 0; i < N; ++i) *(pmas + i) = sin(rand()) * rand() ;
    while(check_sort(N, pmas) == 1);
}

void copy(int N, int *pmas1, int *pmas2)
{
    for (int i = 0; i < N; ++i) *(pmas2 + i) = *(pmas1 + i);
}


int check_sort(int N, int *pmas)
{
    int flag = 1;
    for (int i = 0; i < N; ++i) if (*(pmas + i) < *pmas) {flag = 0; break;}
    return flag;
}


void swap(int *p1, int *p2)
{
    int q = *p1;
    *p1 = *p2;
    *p2 = q;
}
