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

int main(){
    printf("Input length:");
    int N;
    scanf("%d", &N);
    int lst[N];
    int a,b;
    printf("Input range:");
    scanf("%d %d", &a, &b);
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
    int multiply_index = 0;
    int sum_index = 0;
    int uneven_count_btw = 0;

    generate(lst, a, b, N);
    prnt(lst, N);
    //first negative
    for(int i = 0; i<N; i++){
        
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
    int multiply_arr[abs(max_positive_index - min_negative_index) - 1];
    
    for(int i = MIN(min_negative_index, max_positive_index)+1; i < MAX(min_negative_index, max_positive_index); i++){
        multiply *= lst[i];
        multiply_arr[i-MIN(min_negative_index, max_positive_index)-1] = lst[i];
        if (abs(lst[i])%2 == 1){
            uneven_count_btw++;
        }
    }
    int sum_arr[uneven_count_btw];
    for(int i = MIN(min_negative_index, max_positive_index)+1; i < MAX(min_negative_index, max_positive_index); i++){
        if(abs(lst[i]%2)==1){
            uneven_sum += lst[i];
            sum_arr[sum_index] = lst[i];
            sum_index++;
            if(sum_index==uneven_count_btw){
                break;
            }
        }
        else{
            even_count += 1;
        }
    }
    positive_reverse = (int *) malloc(positive_count*sizeof(int));
    
    
    for(int i = N-1; i>-1; i--){
        if(lst[i]>0){
            positive_reverse[m1_index] = lst[i];
            m1_index++;
        }
    }

    for(int i = 0; i<positive_count; i++){
        if(positive_reverse[i]%2 == 1){
            uneven_count+=1;
        }
    }
    
    uneven_indexes = (int *) malloc(uneven_count*sizeof(int));
    
    for(int i = 0; i<positive_count;i++){
        if(positive_reverse[i]%2==1){
            uneven_indexes[m2_index]=i;
            m2_index++;
            if(m2_index==uneven_count){
                break;
            }
        }
    }

    printf("min negative:%d index: %d\n", min_negative, min_negative_index);
    printf("max positive: %d index: %d\n", max_positive, max_positive_index);
    printf("multiply: %d\n", multiply);
    prnt(multiply_arr, abs(max_positive_index - min_negative_index) - 1);
    printf("sum of uneven: %d\n", uneven_sum);
    prnt(sum_arr, uneven_count_btw);
    printf("count of even: %d\n", even_count);
    printf("array of positive:");
    prnt(positive_reverse, positive_count);
    printf("array of uneven indexes:");
    prnt(uneven_indexes, uneven_count);
    return 0;
}
