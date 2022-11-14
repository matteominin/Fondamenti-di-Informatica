/*
    Scrivere una funzione in C che riceve in ingresso una matrice A (nxn), un vettore X (n) e uno scalare L.
    Verifica se X è un autovettore di A con autovalore L.
    (A, X, L sono di tipo float).
 */

#include <stdio.h>
#include <stdlib.h>
typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0
#define REL_ERR 0.01    //errore accettato per confronto tra float

//dichiarazione prototipi funzioni
int buildMatrix(float **dA, int *dim);  //funzione che crea una matrice mxn con i valori in ingresso da tastiera
int buildVect(float **X, int dim); //funzione che crea un vettore di dimensione dimX
Boolean autoVett(float **dA, float *X, int dim, float L);     //controlla se X è un autovettore di A con autovalore L
Boolean isZero(float value);    //controlla se il valore (float) è approssimabile a 0

int main (){
    float *A, *X, L;    //A = matrice mxn | X = vettore di dimensione dimX | L = scalare
    int dim;     //dimensione del vettore (n) e della matrice (nxn)

    printf("Inserisci il valore dello scalare L: ");
    scanf("%f", &L);

    //chiamata funzioni e controllo errori
    int err1 = buildMatrix(&A,&dim);
    int err2 = buildVect(&X, dim);

    if(err1 || err2){   //se ci sono errori stampa il messaggio e termina l'esecuzione
        printf("Errore allocazione memoria");
        return 1;
    }

    Boolean res = autoVett(&A, X, dim, L);

    if(res)
        printf("\nIl vettore X e' autovettore di A con autovalore L");
    else
        printf("\nIl vettore X non e' autovettore di A con autovalore L");

    return 0;
}

//funzione che costruisce la matrice n*n
int buildMatrix(float **dA, int *dim){
    //chiedo la dimensione di A
    printf("\nInserisci la dimensione della matrice A: ");
    scanf("%d", dim);

    //allocazione della matrice linearizzata n*n
    *dA = (float *) malloc (sizeof(float) * (*dim)*(*dim));
    if(*dA == NULL)   return 1;

    //popolamento della matrice
    for(int i=0; i<(*dim)*(*dim); i++){
        printf("\nInserisci il valore %d nella matrice: ", i + 1);
        scanf("%f", &(*dA)[i]);
    }
    return 0;
}

//funzione che crea un vettore di dimensione dimX
int buildVect(float **X, int dim){
    *X = (float *) malloc(sizeof(float)*dim);

    if(*X == NULL) return 1;

    for(int i=0; i<dim; i++){
        printf("\nInserisci il valore %d nel vettore: ", i + 1);
        scanf("%f", &(*X)[i]);
    }

    return 0;
}

Boolean autoVett(float **dA, float *X, int dim, float L){
    float sum = 0;
    int n = 0;
    Boolean no_mismatch_found = TRUE;
    //calcolo A - L*Id  (Id = matrice identità)
    //deve sottrarre L solo dalla diagonale principale di A (i*dim + i) scorre solo gli elementi di diag(A)
    for(int i=0; (i*dim + i) < dim*dim; i++){
        (*dA)[i*dim + i] -= L;
    }

    //moltiplicazione di A*X e confronto se 0
    while(no_mismatch_found && n < dim*dim){
        sum += (*dA)[n] * X[n%dim];
        if((n+1)%dim == 0){
            //chiamata funzione che controlla se sum è approssimabile a 0
            Boolean res = isZero(sum);

            if(!res)    //se non è 0 imposta no_mismatch_found = FALSE
                no_mismatch_found = FALSE;

            sum = 0;
        }
        n++;
    }

    return no_mismatch_found;
}

//controlla se value è approssimabile a 0
Boolean isZero(float value){
    if(value < REL_ERR && value > -REL_ERR)   //se value è compreso tra +- REL_ERR
        return TRUE;

    return FALSE;
}