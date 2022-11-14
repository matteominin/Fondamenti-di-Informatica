/*
    Scrivere una funzione che riceve in input un array di N interi e rimuove in multipli
    di 3 compattando i valori rimasti. Restituisce il numero dei valori rimossi.
 */
#include <stdio.h>
#include <stdlib.h>
void arrayCompact(int **V, int dim, int *count);
int buildArray(int **V, int *dim);

int main() {
    int *V, dim, count;

    int err = buildArray(&V, &dim);
    if(err) return 1;

    arrayCompact(&V, dim, &count);

    for(int i=0; i<dim; i++){
        printf("%d\n", V[i]);
    }

    return 0;
}

int buildArray(int **V, int *dim){
    printf("Inserisci la dimensione dell'array:");
    scanf("%d", dim);

    *V = (int *) malloc(sizeof(int) * (*dim));
    if(*V == NULL) return 1;

    //popolamento array
    for(int i=0; i<*dim; i++){
        printf("\nInserisci il valore numero %d nell'array:", i + 1);
        scanf("%d", &(*V)[i]);
    }

    return 0;
}

void arrayCompact(int **V, int dim, int *count){
    *count = 0;
    for(int i=dim; i>=0; i--){
        if((*V)[i]%3 == 0){
            *count++;

            for(int j=i; j<dim - 1; j++){
                (*V)[j] = (*V)[j+1];
            }
            (*V)[dim - 1] = 0;
        }
    }
}
