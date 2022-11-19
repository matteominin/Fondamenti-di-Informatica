/*
    Scrivere la funzione C che riceve in ingresso una matrice A NxM, di valori int, un vettore XL di valori int
    e restituisce tra i parametri formali un vettore C di valori int allocato all’interno della funzione e calcolato come segue:
        - Se M==L, C è dato dal prodotto C = A * X;
        - Se N==L, C è il prodotto C = AT * X;
        - Altrimenti C è ottenuto come copia di A
 */

#include <stdio.h>
#include <stdlib.h>

void matrixCalc(int *A, int m, int n, int *X, int L, int **C, int *dimC);

int main() {
    int A[6] = {1,3,7,4,5,6};
    int m = 3, n = 2;
    int X[1] = {1,2,};
    int L = 2;
    int *C, dimC;

    matrixCalc(A, m, n ,X, L, &C, &dimC);

    for(int i=0; i<dimC; i++){
        printf("%d ", C[i]);
    }

    return 0;
}


void matrixCalc(int *A, int m, int n, int *X, int L, int **C, int *dimC){
    if(m==L){   //prodotto normale
        int sum=0;
        *C = (int *)malloc(sizeof(int)*n);
        *dimC = n;
        for(int i=0; i<n*m; i++){
            sum += A[i]*X[i%m];
            if((i+1)%m == 0 && i!=0){
                (*C)[(i+1)/m -1] = sum;
                sum = 0;
            }
        }

    }else if(n==L){     //prodotto con trasposta
        *C = (int *)malloc(sizeof(int)*m);
        *dimC = m;
        for(int i=0; i<m; i++){
            (*C)[i] = 0;
            for(int j=0; j<n;j++){
                (*C)[i] += A[i +m*j]*X[j];
            }
        }

    }else{  //copia A in C
        *C = (int *)malloc(sizeof(int)*m*n);
        *dimC = m*n;
        for(int i=0; i<m*n; i++){
            (*C)[i] = A[i];
        }
    }
}