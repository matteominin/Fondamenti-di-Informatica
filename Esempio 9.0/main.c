#include <stdio.h>
#include <stdlib.h>

void arrayCompact(int *A, int N, int **V);

int main(){
    int A[10] = {3,4,4,7,6,1,1,3,9,8}; //1 2 3 2 3 4 5 0 0 0
    int N=10, *V;

    arrayCompact(A, N, &V);

    for(int i=0; i<N; i++){
        printf("%d ", V[i]);
    }

    return 0;
}

void arrayCompact (int *A, int N, int **V){
    *V = (int *)malloc(sizeof(int) * N);
    int index = 1;
    (*V)[0] = A[0];

    for(int i=1; i<N; i++){
        if(A[i] != (*V)[index - 1]){
            (*V)[index] = A[i];
            index++;
        }
    }
}