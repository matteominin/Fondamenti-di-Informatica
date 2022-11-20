/*
    Scrivere la funzione C che riceve in ingresso due matrici A e B di valori float entrambe con N righe ed M colonne, ed opera nel modo seguente:
        - Alloca e calcola la matrice X (di valori float) con N righe ed M colonne i cui elementi sono ottenuti come prodotto tra A e B.
          Il prodotto è eseguito elemento per elemento invece che riga per colonna;
        - Restituisce tra i parametri formali la trasposta della matrice X.
    (Esempio: A2x3 = {1 2 3 4 5 6} B2x3 = {1 2 3 4 5 6} --> X2x3 = {1 4 9 16 25 36} la trasposta XT = {1 16 4 25 9 36})
 */

#include <stdio.h>
#include <stdlib.h>

void arrayCal(int *A, int *B, int m, int n, int **X);

int main() {
    int A[6] = {1,2,3,4,5,6};
    int B[6] = {1,2,3,4,5,6};
    int *X;
    int m = 3, n = 2;

    arrayCal(A, B, m, n, &X);

    for(int i=0; i<m*n; i++){
        printf("%d ", X[i]);
    }

    return 0;
}

void arrayCal(int *A, int *B, int m, int n, int **X){
    *X = (int *)malloc(sizeof(int)*m*n);

    //prodotto
    for(int i=0; i<m*n; i++){
        A[i] = A[i]*B[i];
    }


    //trasposta
    int count = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            (*X)[count] = A[i + j*m];
            count++;
        }
    }
}

