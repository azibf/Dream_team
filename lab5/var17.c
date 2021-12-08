#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

void fill17(int N, int a, int b, int *pmas, int c){
    int counter = 0;
    for (int i = 0; i < N; ++i){
        *(pmas + i) = rand() % (b - a + 1) + a;
        if (*(pmas + i) == 0) ++counter;
        }
    if (counter < 2) fill(N, a, b, pmas, c + 1);
    else printf("amount of generation: %d \n", c);
        }

void out17(int N, int *pmas){
    for (int i = 0; i < N; ++i) printf("%d ", *(pmas + i));
    printf("\n");
}

int pluscounter(int N, int *pmas){
    int counter=0;
    for (int i=0; i<N; i++){
        if (*(pmas+i)>0) counter++;
    }
    return counter;
}

int nechcounter(int N, int *pmas){
    int counter=0;
    for (int i=0; i<N; i++)
        if (abs(*(pmas+i))%2!=0 && *(pmas+i)>0) counter++;
    return counter;
}

void max(int N, int *pmas){
    int maxim = 0;
    int ind=0;
    for (int i=0; i<N; i++){
        if (maxim<*(pmas+i)){
            maxim=*(pmas+i);
            ind=i;
        }
    }
    printf("idx max & max: ");
    printf("%d",ind);
    printf(" ");
    printf("%d",maxim);
    printf("\n");
}

int maxidx(int N, int *pmas){
    int maxim = 0;
    int ind=0;
    for (int i=0; i<N; i++){
        if (maxim<*(pmas+i)){
            maxim=*(pmas+i);
            ind=i;
        }
    }
    return ind;
}

void null(int N, int *pmas){
    int nulll=-1;
    for (int i=0; i<N; i++){
        if (*(pmas+i)==0)
            nulll=i;
    }
    if (nulll==-1) printf(" ");
    else{
        printf("null idx & null ");
        printf("%d",nulll);
        printf(" ");
        printf("%d",0);
        printf("\n");
    }
}

int nullidx(int N, int *pmas){
    int nulll=-1;
    for (int i=0; i<N; i++){
        if (*(pmas+i)==0)
            nulll=i;
    }
    return nulll;
}

void operations(int *pmas,int zb, int zc){
    if (zb<zc){
        int zx=zb;
        zb=zc;
        zc=zx;
    }
    int sredna=0, arsum=1, counter=0;
    printf("interval: \n");
    for (int i=zc+1; i<zb; i++){
        printf("%d",*(pmas + i));
        printf(" ");
        arsum=arsum**(pmas+i);
        if (*(pmas+i)<0) counter++;
        sredna+=*(pmas+i);
    }
    printf("\n");
    printf("product: ");
    printf("%d",arsum);
     printf("\n");
    printf("average: ");
    printf("%d",sredna/(zb-zc-1));
     printf("\n");
    printf("number of negative: ");
    printf("%d",counter);
     printf("\n");
}

int main17(){
    int time_seed = time(NULL);
    srand(time_seed);
    int N, a, b;
    printf("Enter quantity, min and max numbers (min <= 0; max >= 0) ");
    scanf("%d %d %d", &N, &a, &b);
    while (N < 2){
        printf("Wrong quantity!\n Enter number > 1 ");
        scanf("%d", &N);
        }
    while (a > 0 || b < 0 || a > b){
    printf("Wrong max and min values!\n Enter min and max again (min <= 0; max >= 0: min < max) ");
    scanf("%d %d", &a, &b);
    }
int mas[N];
fill17(N, a, b, &mas[0], 0);
out17(N, &mas[0]);
    printf("\n");
    max(N, &mas[0]);
    null(N, &mas[0]);
    operations( &mas[0],maxidx(N, &mas[0]),nullidx(N, &mas[0]));
    int *g = (int *) malloc(N * sizeof(pluscounter(N, &mas[0])));
    if (g!=NULL){
        int array[pluscounter(N, &mas[0])];
        int narray=0;
        for (int i=0; i<N; i++){
            if (mas[i]>0){
                array[narray] = mas[i];
                narray++;
            }
        }
    printf("output positive in reverse order: \n");
    for (int i=pluscounter(N, &mas[0])-1; i>=0; i--){
        printf("%d",array[i]);
        printf(" ");
    }
    printf("\n");
    free(g);
    }
    int *k = (int *) malloc(N * sizeof(nechcounter(N, &mas[0])));
    if (k!=NULL){
        int array[nechcounter(N, &mas[0])];
        int narray=0;
        for (int i=0; i<N; i++){
            if (mas[i]%2!=0 && mas[i]>0){
                array[narray] = i;
                narray++;
            }
        }
    printf("output idx odd numbers: \n");
    for (int i=0; i<nechcounter(N, &mas[0]); i++){
        printf("%d",array[i]);
        printf(" ");
        }
    free(k);
    }
    return 0;
}
