#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>


int pluscounter(int a[100]){
    int counter=0;
    for (int i=0; i<100; i++){
        if (a[i]>0) counter++;
    }
    return counter;
}

int nechcounter(int a[100]){
    int counter=0;
    for (int i=0; i<100; i++)
        if (abs(a[i])%2!=0) counter++;
    return counter;
}

void max(int a[100]){
    int maxim = 0;
    int ind=0;
    for (int i=0; i<100; i++){
        if (maxim<a[i]){
            maxim=a[i];
            ind=i;
        }
    }
    printf("%d",ind);
    printf(" ");
    printf("%d",maxim);
    printf("\n");
}

int maxidx(int a[100]){
    int maxim = 0;
    int ind=0;
    for (int i=0; i<100; i++){
        if (maxim<a[i]){
            maxim=a[i];
            ind=i;
        }
    }
    return ind;
}

void null(int a[100]){
    int nulll=-1;
    for (int i=99; i>=0; i--){
        if (a[i]==0)
            nulll=i;
    }
    if (nulll==-1) printf("¬ массиве нет нулей, перезапустите программу, иначе она сработает неправильно \n");
    else{
        printf("%d",nulll);
        printf(" ");
        printf("%d",0);
        printf("\n");
    }
}

int nullidx(int a[100]){
    int nulll=-1;
    for (int i=99; i>=0; i--){
        if (a[i]==0)
            nulll=i;
    }
    return nulll;
}

void operations(int a[100],int b,int c){
    if (b<c){
        int x=b;
        b=c;
        c=x;
    }
    int sredna=0, arsum=1, counter=0;
    for (int i=c+1; i<b; i++){
        arsum=arsum*a[i];
        if (a[i]<0) counter++;
        sredna+=a[i];
    }
    printf("произведение элементов ");
    printf("%d",arsum);
     printf("\n");
    printf("среднее арифметическое ");
    printf("%d",sredna);
     printf("\n");
    printf("количество отрицательных ");
    printf("%d",counter);
     printf("\n");
}

int main17(){
    int n=100;
    int arr[n];
    srand (time (NULL));
    for ( int i = 0; i < n; i ++){
        arr [i] = rand ()%100 - 50;
        printf("%d",arr[i]);
        printf(" ");
    }
    printf("\n");
    max(arr);
    null(arr);
    operations(arr,maxidx(arr),nullidx(arr));
    int *a = (int *) malloc(n * sizeof(pluscounter(arr)));
    if (a!=NULL){
        int array[pluscounter(arr)];
        int narray=0;
        for (int i=0; i<100; i++){
            if (arr[i]>0){
                array[narray] = arr[i];
                narray++;
            }
        }
    printf("вывод положительных в обратном пор€дке: \n");
    for (int i=pluscounter(arr)-1; i>=0; i--){
        printf("%d",array[i]);
        printf(" ");
    }
    printf("\n");
    free(a);
    }
    int *b = (int *) malloc(n * sizeof(nechcounter(arr)));
    if (b!=NULL){
        int array[nechcounter(arr)];
        int narray=0;
        for (int i=0; i<100; i++){
            if (abs(arr[i])%2!=0){
                array[narray] = i;
                narray++;
            }
        }
    printf("вывод индексов нечентных \n");
    for (int i=0; i<nechcounter(arr); i++){
        printf("%d",array[i]);
        printf(" ");
        }
    free(b);
    }
    return 0;
}
