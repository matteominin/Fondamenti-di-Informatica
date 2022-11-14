#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0

/* Dichiarazione prototipi funzioni*/
void check(int N);
Boolean is_constant(int *V, int N);

int main() {
    int N;

    do{
        printf("\nInserisci il valore di N: ");
        scanf("%d", &N);
    }while(N<=0);       //Il valore N deve essere maggiore di 0

    check(N);
    return 0;
}

//Funzione che richiede di inserire i numeri a tastiera
void check(int N){
    int *V, count;      //dichiaro count fuori, altrimenti è out of scope nel do-while
    V = (int *) malloc (sizeof(int) * N);  //alloco un array di dimensione N

    for(count=0; count<N -1; count++){                   //immetto nell'array i primi valori tranne l'ultimo
        printf("\nInserisci un valore+: ");
        scanf("%d", &V[count]);
    }

    do{
        printf("\nInserisci un valore: ");
        scanf("%d",&V[count]);
        count = (count + 1) % N;         //si incrementa a ogni passo count, fino a quando count diventa uguale a N e quindi viene riportato a 0 dall'operazione di resto
    }while(!is_constant(V,N));       //controlla se la funzione è costante

    free(V);
}

//Funzione che controlla se l'array è costante
Boolean is_constant(int *V, int N){
    Boolean no_mismatch_found = TRUE;

    for(int i=1; i<N; i++){   //i = 1, è inutile confrontare l'elemento 0 con se stesso
        if(V[0] != V[i]) {       //se il valore V[0] è diverso dai successivi imposta no_mismatch_found = FALSE
            no_mismatch_found = FALSE;
            return no_mismatch_found;
        }
    }
    return no_mismatch_found;
}