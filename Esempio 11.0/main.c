/*
    Scrivere la funzione C che riceve in ingresso un array di interi A,la sua dimensione N, un intero K,
    ed un intero LR e restituisce tra i parametri formali un array di interi V allocato all’interno della funzione.
    La funzione opera nel modo seguente:
        - I valori dell’array A sono inizialmente copiati in V;
        - I valori dell’array V sono quindi soggetti a shift circolare verso sinistra (se LR ha valore 0) o verso destra
    (se LR ha valore 1) di un numero di posizioni pari a K.
    (Esempio: A={1,2,3,4,5}, K=3, LR=1 -> V={3,4,5,1,2}).
 */

#include <stdio.h>
#include <stdlib.h>

void arrayShift(int *A, int dim, int **V, int K, int LR);

int main() {
    int A[5] = {1,2,3,4,5};
    int N = 5, K = 3, LR = 1;
    int *V;

    arrayShift(A, N, &V, K, LR);

    for(int i=0; i<N;i++){
        printf("%d ", V[i]);
    }

    return 0;
}

void arrayShift(int *A, int dim, int **V, int K, int LR){
    //alloco array
    *V = (int *)malloc(sizeof(int)*dim);

    //copio i valori di A nel nuovo array V
    for(int i=0; i<dim; i++){
        (*V)[i] = A[i];
    }

    if(LR){     //shift verso destra
        int tmp, shift;
        for(int i=0; i<K; i++){
            shift = (*V)[0];
            printf("%d\n", shift);

            for(int j=0; j<dim; j++){
                tmp = (*V)[(j+1)%dim];
                (*V)[(j+1)%dim] = shift;
                shift = tmp;
            }
        }
    }

}
