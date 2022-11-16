/*
    Definire la funzione C che riceve in ingresso un array di interi A di dimensione N ed alloca e determina l'array H
    come istogramma di A. L'istogramma deve avere un elemento per ogni valore distinto di A. Per un elemento di H in posizione i,
    la frequenza delle occorrenze del valore H[i] in A deve essere riportata in posizione i+1
    (es., per A={3,2,3,4,1,1,7,7,7}, risulta H={3,2,2,1,4,1,1,2,7,3}).
    L'array H deve essere restituito tra i parametri formali della funzione insieme al numero finale dei suoi valori.
    La funzione deve anche restituire come valore di ritorno, TRUE se la funzione termina correttamente, FALSE altrimenti.
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int Boolean;
Boolean istogramma(int *A, int N, int **H, int *Hsize);
#define TRUE 1
#define FALSE 0


int main() {
    int A[10] = {1, 3, 4,5,2,5,2,6,7,4}; //1 1 3 1 4 2 5 2 2 2 6 1 7 1
    int N = 10;
    int *H, Hsize = 0;
    istogramma(A, N, &H, &Hsize);

    for(int i=0; i<Hsize; i++){
        printf("\n%d", H[i]);
    }
    return 0;
}

Boolean istogramma(int *A, int N, int **H, int *Hsize){
    int index = 0;
    *H = (int *)malloc(sizeof(int)*N);
    if(*H == NULL) return FALSE;

    for(int i=0; i<N; i++){
        //controllo se l'elemento è già stato usato
        int found = 0;
        for(int j=i-1; j>=0; j--){
            if(A[i] == A[j]){
                found = 1;
                break;
            }
        }

        //se l'elemento non è già stato incluso in H
        if(!found){
            int count = 0;
            (*H)[index] = A[i];
            (*Hsize)++;

            //conta quanti valori sono uguali
            for(int j=i; j<N; j++){
                if(A[j] == A[i])
                    count++;
            }
            (*H)[index + 1] = count;
            (*Hsize)++;

            index += 2;
        }
    }
    return TRUE;
}