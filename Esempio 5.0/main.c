/*
    Stampare i numeri primi minori di N (Utilizzo il crivello di Eratostene)
 */
#include <stdio.h>
#include <stdlib.h>

void primeNumbers(int N);

int main(){
    int N;
    printf("Inserisci un numero:");
    scanf("%d", &N);

    primeNumbers(N);

    return 0;
}

void primeNumbers(int N){
    int *V;

    //inizializzazione array a 1
    V = (int *) malloc(sizeof(int)*N);
    for(int i=0; i<N; i++){
        V[i]=1;
    }
    printf("1");

    //crivello di Eratostene
    for(int i=2; i<N; i++){
        if(V[i]) {
            printf("\n%d", i);

            for(int j=2*i; j<N; j+=i){
                V[j] = 0;
            }
        }
    }

    free(V);
}