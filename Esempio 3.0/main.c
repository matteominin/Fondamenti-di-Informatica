/*
    Scrivere una funzione C che riceve in ingresso due array di numeri
    interi A1 e A2 di lunghezza N1 e N2 (N1 > N2) e verifica se A2 è contenuto in A1
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0

Boolean array_inclusion(int *A1, int *A2, int N1, int N2);

int main(){
    int *A1, *A2, N1, N2;

    do{     //richiede d'inserire la dimensione di A1 finché non viene inserito un numero maggiore di 0
        printf("\nInserisci la dimensione del primo array: ");
        scanf("%d", &N1);
    }while(N1<=0);

    do{     //richiede d'inserire la dimensione di A2 finché non viene inserito un numero minore di N1
        printf("\nInserisci la dimensione del secondo array: ");
        scanf("%d", &N2);
    }while(N2>N1);

    //allocazione degli array A1 e A2 di dimensioni N1 e N2
    A1 = (int *) malloc (sizeof(int)*N1);
    A2 = (int *) malloc (sizeof(int)*N2);

    //inserimento dei valori nell'array A1
    for(int i=0; i<N1;i++){
        printf("\nInserisci l'elemento %d di A1: ", i+1);
        scanf("%d", &A1[i]);
    }

    //inserimento dei valori nell'array A2
    for(int i=0; i<N2;i++){
        printf("\nInserisci l'elemento %d di A2: ", i+1);
        scanf("%d", &A2[i]);
    }

    //chiamata alla funzione che controlla se A2 è contenuto in A1
    Boolean result = array_inclusion(A1, A2, N1, N2);

    //stampa risultato
    if(result == 1){
        printf("\nL'array A2 e' contenuto in A1");
    }else{
        printf("\nL'array A2 non e' contenuto in A1");
    }

    return 0;
}

//funzione che controlla se A2 è contenuto in A1
Boolean array_inclusion(int *A1, int *A2, int N1, int N2){
    Boolean found = FALSE;
    for(int i=0; i<=N1 - N2; i++){      //itera i valori di A1 alla ricerca di un valore uguale a quello in posizione 0 di A2
        if(A1[i] == A2[0]){
            for(int j=1; j<N2;j++){     //se la condizione if è vera itera all'interno di A2 e controlla se il valore A2[j] = A[i + j]
                if(A2[j] != A1[i+j]) break;     //se individua un elemento che non corrisponde esce dal ciclo for

                if(j == (N2 -1)) found = TRUE;  //se arriva all'ultima iterazione (j == (N2 -1)) ha trovato il valore
            }
        }
    }

    return found;
}



