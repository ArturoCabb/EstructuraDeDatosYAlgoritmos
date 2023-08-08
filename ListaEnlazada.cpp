#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct Lista {
    int numero;
    Lista *siguiente = NULL;
} *inicial;

void insertarFinal(int nu) {
    Lista *nuevo = new Lista;
    nuevo->numero = nu;
    if (inicial == NULL)
        inicial = nuevo;
    else {
        Lista *actual = inicial;
        while (actual->siguiente != NULL)
            actual = actual->siguiente;
        actual->siguiente = nuevo;
    }
}

void insertarInicio(int nu) {
    Lista *nuevo = new Lista;
    nuevo->numero = nu;
    nuevo->siguiente = inicial;
    inicial = nuevo;
}

void imprime() {
    Lista *aux = inicial;
    while (aux != NULL) {
        std::cout << aux->numero << std::endl;
        aux = aux->siguiente;
    }
}

int main() {
    insertarFinal(5);
    insertarFinal(10);
    insertarFinal(2);
    imprime();
    
    return 0;
}
