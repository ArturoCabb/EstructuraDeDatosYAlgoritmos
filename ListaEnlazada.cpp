#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct Lista {
    int numero;
    int edad;
    Lista *siguiente, *anterior;
} *inicial, *final, *nuevo;

void insertar(int nu, int ed){
    nuevo = new Lista;
    nuevo->numero = nu;
    nuevo->edad = ed;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    if (inicial == NULL)
    {
        inicial = nuevo;
        final = nuevo;
    }
    else {
        final->siguiente = nuevo;
        nuevo->anterior = final;
        final = nuevo;
    }
}

void imprime() {
    Lista *aux;
    aux = final;
    while (aux != NULL) {
        std::cout << aux->numero << " tiene la edad de: " << aux->edad << std::endl;
        aux = aux->anterior;
    }
}

int main() {
    insertar(5, 10);
    insertar(10, 20);
    insertar(2, 15);
    imprime();

    return 0;
}