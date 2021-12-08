#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


void out(int N, int *pmas) //вывод массива
{
    for (int i = 0; i < N; ++i) printf("%d ", *(pmas + i));
    printf("\n");
}

void fill(int N, int a, int b, int *pmas, int c) //заполнение массива с учёто особенностей задания
{
    int counter = 0;
    for (int i = 0; i < N; ++i)
    {
        *(pmas + i) = rand() % (b - a + 1) + a;
        if (*(pmas + i) == 0) ++counter;
    }
    if (counter < 2) fill(N, a, b, pmas, c + 1);
    else printf("amount of generation: %d \n", c);
}

void swap(int *p1, int *p2) //смена элементов местами
{
    int q = *p1;
    *p1 = *p2;
    *p2 = q;
}

int main6()
{
    int time_seed = time(NULL);
    srand(time_seed);
    int N, a, b;
    printf("Enter quantity, min and max numbers (min <= 0; max >= 0) ");
    scanf("%d %d %d", &N, &a, &b);
    while (N < 2)
    {
        printf("Wrong quantity!\n Enter number > 1 ");
        scanf("%d", &N);
    }
    while (a > 0 || b < 0 || a > b)
    {
        printf("Wrong max and min values!\n Enter min and max again (min <= 0; max >= 0: min < max) ");
        scanf("%d %d", &a, &b);
    }
    int mas[N];

    // task 1
    fill(N, a, b, &mas[0], 0);
    out(N, &mas[0]);

    // task 2
    printf("\n");
    int counter = 0, index1 = -1, index2 = -1, max_elem = a;
    for (int i = N - 1; i > -1; --i)
    {
        if (mas[i] == 0) if (counter < 2) {++ counter; if (counter == 2) index1 = i;}
        if (abs(mas[i]) > max_elem) {max_elem = abs(mas[i]); index2 = i;}
        if (index1 != -1 && index2 != -2) break;
    }
    printf("element:%d index:%d \n", mas[index1], index1);
    printf("element:%d index:%d \n", mas[index2], index2);

    //task 3
    printf("\n");
    counter = 0;
    max_elem = a;
    int min_elem = b, sum = 0;
    if (index1 > index2) swap(&index1, &index2);
    for (int i = index1 + 1; i < index2; ++i)
    {
        sum += mas[i];
        if (mas[i] > max_elem) max_elem = mas[i];
        if (mas[i] < min_elem) min_elem = mas[i];
        if (mas[i] % 2 == 1) ++counter;
        printf("%d ", mas[i]);
    }
    printf("\n");
    printf("sum: %d \n", sum);
    printf("min elem: %d, max elem: %d\n", min_elem, max_elem);
    printf("arithmetic mean of max and min: %.1f \n", ((float)min_elem + (float)max_elem) /2);
    printf("number of odd numbers: %d \n", counter);
    //task 4
    printf("\n");
    int counter_minus = 0, counter_plus = 0;
    counter = 0;
    int *a1 = NULL, *a2 = NULL;
    a1 = (int *) malloc(N * sizeof(int));
    a2 = (int *) malloc(1 * sizeof(int));
    for (int i = 0; i < N; ++i)
    {
        if (mas[i] < 0) {a1[counter_minus] = mas[i]; ++counter_minus;}
        else
        {
            if (mas[i] > 0)
            {
                ++counter;
                a2 = (int *) realloc(a2, counter * sizeof(int));
                a2[counter - 1] = i;
            }
            ++counter_plus;
            a1[N - counter_plus] = mas[i];
        }
    }
    printf("source array : ");
    out(N, &mas[0]);
    printf("array of negative: ");
    out(N, &a1[0]);
    if (counter != 0) {printf("array of positive's index: "); out(counter, &a2[0]);}
    else printf("Empty");
    free(a1); free(a2);
}
