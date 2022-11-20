/*
    Scrivere la funzione C che riceve in ingresso un array di valori interi V e la sua dimensione N, ed opera nel modo seguente:
        - Alloca e calcola un nuovo array di valori float W i cui elementi sono dati dal rapporto tra due elementi consecutivi di V. L’ultimo elemento di V è diviso per il primo;
        - Ritorna FALSE nel caso sia presente una divisione per 0, TRUE altrimenti;
        - Restituisce tra i parametri formali l’array W.
    (Esempio: V = {4, 2, 2, 4, 6, 1}, N = 6 --> W = {4/2, 2/2, 2/4, 4/6, 6/1, 1/4} = {2, 1.0, 0.5, 0.6666666, 6.0, 0.25})
 */

#include <stdio.h>
#include <stdlib.h>
typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0

Boolean vectCalc(int *V, int n, float **W);

int main() {
    int V[6] = {4,2,2,0,6,1};
    int N = 6;
    float *W;

    int err = !vectCalc(V, N, &W);

    if(err){
        printf("Errore, non si può dividere per 0");
    }else{
        for(int i=0; i<N; i++){
            printf("%f ", W[i]);
        }\
    }

    return 0;
}

//calcolo divisione
Boolean vectCalc(int *V, int n, float **W){
    *W = (float *)malloc(sizeof(float)*n);
    if(*W == NULL) return FALSE;
    for(int i=0; i<n; i++){
        if(V[(i+1)%n] == 0) return FALSE;
        (*W)[i] = (float) V[i]/V[(i+1)%n];
    }
    return TRUE;
}