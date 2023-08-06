#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct Lista {
    int numero;
    Lista *next;
} *inicial, *final, *nuevo;

void insertar(int nu) {
    nuevo = new Lista;
    nuevo->numero = nu;
    nuevo->next = NULL;
    if (inicial == NULL)
    {
        inicial = nuevo;
        final = nuevo;
    }
    else {
        nuevo->next = NULL;
        final->next = nuevo;
        final = nuevo;
    }
}

void imprime() {
    Lista *aux;
    aux = inicial;
    while (aux != NULL) {
        printf("%d ", aux->numero);
        aux = aux->next;
    }
    printf("\n");
}

int main() {
    insertar(5);
    insertar(10);
    insertar(2);
    imprime();
    
    return 0;
}
