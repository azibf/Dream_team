#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))



void generate(int arr[], int a, int b, int len){
    srand(time(NULL));
    int x;
    for(int i = 0; i<len; i++){
        x = rand();
        arr[i] = x%(b-a+1) + a;
    }
}

void prnt(int arr[], int len){
    for(int i = 0; i<len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main15(){
    printf("Input length:");
    int N;
    scanf("%d", &N);
    while (N < 2)
    {
        printf("Wrong quantity!\n Enter number > 1 ");
        scanf("%d", &N);
    }
    int lst[N];
    int a,b;
    printf("Input range (min < 0 && max > 0):");
    scanf("%d %d", &a, &b);
    while (a > 0 || b < 0 || a > b)
    {
        printf("Wrong max and min values!\n Enter min and max again (min <= 0; max >= 0: min < max) ");
        scanf("%d %d", &a, &b);
    }
    int min_negative = 1;
    int min_negative_index;
    int max_positive = 0;
    int max_positive_index;
    int multiply = 1;
    int uneven_sum = 0;
    int even_count = 0;
    int uneven_count = 0;
    int positive_count = 0;
    int *positive_reverse;
    int *uneven_indexes;
    int m1_index = 0;
    int m2_index = 0;

    generate(lst, a, b, N);
    prnt(lst, N);
    //first negative
    for(int i = 0; i<N; i++){
        if(lst[i]%2==1){
            uneven_count++;
        }
        if (lst[i]<0 && lst[i]<min_negative){
            min_negative = lst[i];
            min_negative_index = i;
        }
        else if(lst[i]>0){
            positive_count++;
            if(lst[i]>max_positive){
                max_positive = lst[i];
                max_positive_index = i;
            }
        }
    }

    for(int i = MIN(min_negative_index, max_positive_index)+1; i < MAX(min_negative_index, max_positive_index); i++){
        multiply *= lst[i];
        if(abs(lst[i]%2)==1){
            uneven_sum += lst[i];
        }
        else{
            even_count += 1;
        }
    }

    positive_reverse = (int *) malloc(positive_count*sizeof(int));
    uneven_indexes = (int *) malloc(uneven_count*sizeof(int));

    for(int i = N-1; i>-1; i--){
        if(lst[i]>0){
            positive_reverse[m1_index] = lst[i];
            m1_index++;
        }
        if(abs(lst[i]%2) == 1){
            uneven_indexes[m2_index] = i;
            m2_index++;
        }
    }

    printf("min negative:%d index: %d\n", min_negative, min_negative_index);
    printf("max positive: %d index: %d\n", max_positive, max_positive_index);
    printf("multiply: %d\n", multiply);
    printf("sum of uneven: %d\n", uneven_sum);
    printf("count of even: %d\n", even_count);
    printf("array of positive:");
    prnt(positive_reverse, positive_count);
    printf("array of uneven indexes:");
    prnt(uneven_indexes, uneven_count);
    return 0;
}
