/*
    Scrivere la funzione C che riceve in ingresso un array di float A, un array di unsigned short int B, e la loro dimensione N ed opera nel modo seguente:
        - Alloca un array C e lo restituisce tra i parametri formali della funzione;
        - I valori degli elementi di C sono ottenuti come prodotto tra il valore degli elementi di A e degli elementi
          di B con stesso indice (i valori di B possono essere solo 0 od 1, in caso contrario la funzione termina).
    La funzione deve anche restituire tra i parametri formali il numero di elementi di C che hanno valore calcolato > di 0.
    Il valore restituito dalla funzione è TRUE nel caso di esecuzione corretta, FALSE altrimenti.
    (Esempio: A={1,2,3,4,5}, B={0,1,0,1,1}, N=5 -> C={0,2,0,4,5})
 */


#include <stdio.h>
#include <stdlib.h>
typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0

Boolean arryCheck(int *A, int N, int *B, int **C, int *nonZero);

int main() {
    int A[5] = {1,2,3,4,5};
    int N = 5;
    int B[5] = {0,1,0,1,1};
    int *C, nonZero;

    int err = !arryCheck(A, N, B, &C, &nonZero);
    if(err) {
        printf("Errore, uno dei valori di B non è ne 0 ne 1");
    }else{
        for(int i=0; i<N; i++)
            printf("%d ", C[i]);
    }




    return 0;
}

Boolean arryCheck(int *A, int N, int *B, int **C, int *nonZero){
    *nonZero = 0;
    *C = (int *)malloc(sizeof(int) * N);
    for(int i=0; i<N; i++){
        if(B[i] != 0 && B[i] != 1) { return FALSE; }
        (*C)[i] = A[i] * B[i];
        if((*C)[i] != 0) *nonZero++;
    }
    return TRUE;
}