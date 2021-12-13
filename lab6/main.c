#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>



int main()
{
    int time_seed = time(NULL);
    srand(time_seed);
    int N;
    double time[5];
    char *fastest_name = "Bubble";
    char *slowest_name = "Bubble";
    double fastest = 1000000, slowest = 0;
    int sort_res[5];
    char *sorts_name[] = {"Bubble    ", "Insertion ", "Shell     ", "Quick     ", "Merge     ",};
    printf("Enter quantity numbers ");
    scanf("%d", &N);
    while (N < 2)
    {
        printf("Wrong quantity!\n Enter number > 1 ");
        scanf("%d", &N);
    }
    int q = 0;

    printf("Enter 0 (mod 4) - to work with int, 1 (mod 4) - signed short, 2 (mod 4) - unsigned long; 3 (mod 4) float ");
    scanf("%d", &q);
    int *mas = NULL;
    mas = (int*) malloc(N * sizeof(int));
    switch(q)
    {
        case 0:{fill_int(N, &mas[0]); break;}
        case 1:{fill_s_short(N, &mas[0]); break;}
        case 2:{fill_uns_long(N, &mas[0]); break;}
        default:{fill_float(N, &mas[0]);break;}
    }
    int* **p = NULL;
    p = (int **) malloc(5 * sizeof(int *));
    for (int i = 0; i < 5; i++) p[i] = (int *) malloc(N * sizeof(int));
    out(N, &mas[0]);
    printf("\n");
    double start_t, end_t;
    printf("\n|----------------------------|\n");
    printf("|   Name   |  Time  | Result |");
    printf("\n|----------------------------|\n");
    for (int i = 0; i < 5; ++ i)
    {
        copy(N, &mas[0], &p[i][0]);
        start_t = clock();
        switch(i)
        {
            case 0:{Bubble_sort(N, &p[i][0]);break;}
            case 1:{Insertion_sort(N, &p[i][0]);break;}
            case 2:{Shell_sort(N, &p[i][0]);break;}
            case 3:{Quick_sort(p[i], 0, N - 1);break;            }
            case 4:{Merge_sort(N, &p[i][0]);break;}
        }
        //out(N, &p[i][0]);
        end_t = clock();
        sort_res[i] = check_sort(N, &p[i][0]);

        time[i] = (end_t - start_t) / 1000;
        printf("|%.10s| %3.2f |    %d    |", sorts_name[i], time[i], sort_res[i]);
        printf("\n|----------------------------|\n");
        if (time[i] > slowest) {slowest = time[i], slowest_name = sorts_name[i];}
        if (time[i] < fastest) {fastest = time[i], fastest_name = sorts_name[i];}
    }
    printf("The fastest sort id %s time: %.1f \n", fastest_name, fastest);
    printf("The slowest sort id %s time: %.1f \n", slowest_name, slowest);
    printf("All time: %.1f \n", time[0] + time[1] + time[2] + time[3] + time[4]);
    for (int i = 0; i < 5; i++) free(p[i]);
    free(p);
}

