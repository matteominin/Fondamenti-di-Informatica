#include <stdio.h>
#include <stdlib.h>

struct List{
    int *buffer;
    int size;
    int head;
    int tail;
};
typedef struct List List;
typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0

//dichiarazione prototipi funzioni
int initList(List *ptr, int size);      //inizializza la lista
int popolamento(List *ptr, int n);      //popola la lista
void visit(List L);                     //stampa gli elementi della lista

int headInsert(List *ptr, int value);   //inserisce in testa
int tailInsert(List *ptr, int value);   //inserimento in coda
int headDelete(List *ptr);              //cancellazione in testa
int tailDelete(List *ptr);              //cancellazione in coda
Boolean search(List L, int target);     //ricerca un valore nella lista

int main() {
    List a;
    int size = 10;

    //inizializzazione lista
    int err1 = initList(&a, size);
    if(err1) {
        printf("\nErrore inizializzazione lista.");
        return 1;
    }

    //popolamento lista
    int err2 = popolamento(&a, 5);
    if(err2){
        printf("\nErrore, la lista e' piena.");
        return 1;
    }

    visit(a);
/*
    int err3 = headInsert(&a, 6);
    if(err3){
        printf("\nErrore, l'array è già pieno.");
        return 1;
    }

    int err4 = headDelete(&a);
    if(err4){
        printf("\nErrore, l'array è vuoto.");
    }

    int err5 = tailInsert(&a, 8);
    if(err5){
        printf("\nErrore, l'array è pieno.");
    }

    int err6 = tailDelete(&a);
    if(err6){
        printf("\nErrore, l'array è vuoto.");
    }

    Boolean res = search(a, 5);
    if(res){
        printf("\nIl valore e' presente nella lista");
    }else{
        printf("\nIl valore non e' contenuto nella lista");
    }
*/

    return 0;
}

//inizializza la lista
int initList(List *ptr, int size){
    ptr->buffer = (int *) malloc(sizeof(int)*size);
    if(ptr->buffer == NULL)
        return 1;

    ptr->size = size;
    ptr->head = 0;
    ptr->tail = 0;

    return 0;
}

//popola la lista con n elementi
int popolamento(List *ptr, int n){
    for (int i = 0; i < n; ++i) {
        ptr->tail += 1;
        if(ptr->head == ptr->tail + 1)
            return 1;

        printf("\nInserisci un valore in lista:");
        scanf("%d", &(ptr->buffer)[i]);
    }
    return 0;
}

//stampa gli elementi contenuti nella lista
void visit(List L){
    printf("\nI valori nella lista sono:");
    for(int i = L.head; i != L.tail; i = (i+1)%L.size){
        printf(" %d", L.buffer[i]);
    }
}

//inserimento in testa
int headInsert(List *ptr, int value){
    //verifico che la lista non sia satura
    if(ptr->head != (ptr->tail + 1)%ptr->size) {
        ptr->head = (ptr->head - 1 + ptr->size)%ptr->size;  //se head è 0 diventerebbe negativo, in questo modo è sempre positivo
        ptr->buffer[ptr->head] = value;
        return 0;
    }

    return 1;
}

//Cancellazione in testa
int headDelete(List *ptr){
    if(ptr->head != ptr->tail){     //controlla se la lista è vuota
        ptr->head = (ptr->head + 1 )%ptr->size;     //iterazione circolare array (non serve + ptr->size perché è sempre intero)
        return 0;
    }
    return 1;
}


//inserimento in coda
int tailInsert(List *ptr, int value){
    //verifico se la lista non è piena
    if(ptr->head != (ptr->tail + 1)%ptr->size){
        ptr->buffer[ptr->tail] = value;
        ptr->tail = (ptr->tail + 1)%ptr->size;
        return 0;
    }
    return 1;
}

//cancellazione in coda
int tailDelete(List *ptr){
    //verifico se l'array è vuoto
    if(ptr->head != ptr->tail){
       ptr->tail = (ptr->tail - 1 + ptr->size)%ptr->size;
       return 0;
    }
    return 1;
}

Boolean search(List L, int target){
    for(int i=L.head; i != L.tail; i = (i+1)%L.size){
        if(L.buffer[i] == target)
            return TRUE;
    }
    return FALSE;
}