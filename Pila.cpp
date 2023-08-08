// Sigue el principio de LiFo el último en entrar es el primero en salir

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct Pila
{
    int numero;
    Pila *siguiente;
} *inicial, *final, *nuevo, *penultimo, *actual;

void insertar(int nu) {
    nuevo = new Pila;
    nuevo->numero = nu;
    nuevo->siguiente = NULL;
    if (inicial == NULL) {
        inicial = nuevo;
        final = nuevo;
    }
    else {
        final->siguiente = nuevo;
        final = nuevo;
    }
}

void retirar() {
    if (inicial == NULL) std::cout << "La pila está vacia" << std::endl;
    else {
        actual = inicial;
        while (actual->siguiente != NULL) {
            penultimo = actual;
            actual = actual->siguiente;
        }
        penultimo->siguiente = NULL;
        final = penultimo;
    }
}

void imprime() {
    Pila *aux;
    aux = inicial;
    while (aux != NULL)
    {
        std::cout << aux->numero << std::endl;
        aux = aux->siguiente;
    }
}

int main() {
    insertar(5);
    insertar(10);
    insertar(2);
    imprime();
    imprime();
    imprime();

    return 0;
}
