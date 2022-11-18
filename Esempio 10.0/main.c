/*
    Scrivere la funzione C che riceve in ingresso un array di interi A di dimensione N,
    un intero target, ed un numero di ripetizioni M>0 e restituisce tra i parametri formali un array di interi V ottenuto
    nel modo seguente: i valori di A diversi da target sono copiati in V; per ogni valore in A uguale a target è copiata in V
    una sequenza di M valori uguali a target. La funzione deve anche restituire tra i parametri formali il numero di valori (size) copiati in V.
    (Esempio: A={5,1,3,1,1}, target=1, M=2 -> V={5,1,1,3,1,1,1,1}, size = 8).
 */

#include <stdio.h>
#include <stdlib.h>

void arrayManipulation(int *A, int N, int **V, int M, int target, int *dimV);

int main() {
    int A[10] = {1, 3, 2, 4, 5, 4, 3, 1, 1, 1};
    int N = 10, M = 2, target = 1, *V, dimV;

    arrayManipulation(A, N, &V, M, target, &dimV);

    for(int i=0; i<dimV; i++){
        printf("%d ", V[dimV]);
    }

    return 0;
}

void arrayManipulation(int *A, int N, int **V, int M, int target, int *dimV){
    *V = (int *)malloc(sizeof(int)*N*M);
    *dimV = 0;

     for(int i=0; i<N; i++){
         if(A[i] == target){
             for(int j=0; j<M; j++){
                 (*V)[*dimV] = target;
                 *dimV++;
             }
         }else{
             (*V)[*dimV] = A[i];
             *dimV++;
         }
     }
}
