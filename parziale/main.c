#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0

Boolean array_ord(int *V, int *W, int N, int **A);

int main() {
    int V[4] = {1,4,6,8};
    int W[4] = {2,3,9,10};
    int N = 4;
    int *A;

    array_ord(V, W, N, &A);

    for(int i=0; i<2*N; i++){
        printf("%d ", A[i]);
    }

    return 0;
}

Boolean array_ord(int *V, int *W, int N, int **A){
    *A = (int *)malloc(sizeof(int)*2*N);
    if(*A == NULL) return FALSE;

    int i=0, j=0, k=0;

    while(i<N && j<N){
        if(V[i] > W[j])
            (*A)[k++] = W[j++];
        else
            (*A)[k++] = V[i++];
    }

    if(i<N){
        for(int L=i; L<N; L++)
            (*A)[k++] = V[L];
    }

    if(j<N){
        for(int L=j; L<N; L++)
            (*A)[k++] = W[L];
    }

    return TRUE;
}