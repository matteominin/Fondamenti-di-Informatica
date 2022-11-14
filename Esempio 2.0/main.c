#include <stdio.h>
#include <stdlib.h>

/*
    Scrivere una funzione che dati in ingresso 2 valori interi N e sum,
    acquisisce numeri da tastiera fino a quando la somma degli
    ultimi N numeri interi inseriti è uguale a sum.
 */

//Dichiarazione prototipo funzione
void check(int N, int target);

int main() {
    int N, sum;

    do{         //controllo che N sia maggiore di 0
        printf("\nInserisci il valore di N: ");
        scanf("%d", &N);
    }while(N<=0);

    printf("\nInserisci il valore target(sum): ");
    scanf("%d", &sum);

    check(N, sum);      //chiamata alla funzione check
    return 0;
}

void check(int N, int target){
    int count=0, sum=0, *V;
    V = (int *) malloc (sizeof(int) * sum);     //allocazione di un'array V di N elementi

    for(int i=0; i<N; i++){         //inizializzazione dell'array V con i primi N valori
        printf("\nInserisci un valore: ");
        scanf("%d", &V[i]);
        sum += V[i];
    }

    while(sum != target){           //richiesta d'inserimento di un valore finché la somma non è uguale al target
        sum -= V[count];            //viene sottratto il valore più vecchio che presto verrà sostituito (per ottimizzare il calcolo)
        printf("\nInserisci un valore: ");
        scanf("%d", &V[count]);
        sum += V[count];
        count = ++count % N;    //indice d'iterazione array, count viene incrementato e ne viene fatto il resto, quando count sarà uguale a N verrà resettato
    }
}