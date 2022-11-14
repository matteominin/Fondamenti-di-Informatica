/*
    Definire la funzione in C che riceve come parametri un valore N e acquisisce
    numeri interi da tastiera finché gli ultimi N numeri interi inseriti non sono uguali
*/

#include <stdio.h>
void check(int N);

int main() {
    int N;
    printf("\nInserisci il numero N: ");
    scanf("%d", &N);
    check(N);
}

void check(int N){
    int actual;
    int tmp;
    int count = 1;

    printf("\nInserisci un numero: ");      //Richiesta primo valore da assegnare alla variabile actual
    scanf("%d",&actual);

    while(count < N){
        printf("\nInserisci un numero: ");  //Richiesta valori successivi da confrontare
        scanf("%d", &tmp);
        if(tmp == actual)       //se il valore inserito (tmp) è uguale al valore di actual, il counter viene incrementato
            count ++;
        else {                  //altrimenti viene impostato actual al nuovo valore e il counter viene riportato a 1
            actual = tmp;
            count = 1;
        }
    }
}


/*
    Soluzione:
    Chiedo il primo valore e lo salvo nella variabile actual, chiedo altri valori fino
    al raggiungimento della guardia count < N.
    Se il nuovo valore inserito (salvato in tmp) è diverso da quello in actual, il counter viene
    reimpostato a 1 e alla variabile actual viene assegnato il valore di tmp.
 */
