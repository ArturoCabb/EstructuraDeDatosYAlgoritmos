// Sigue FiFo el primero en entrar es el primero en salir

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct Fila
{
    int numero;
    Fila *siguiente;
} *inicial, *final, *nuevo, *penultimo, *actual;

void insertar(int nu) {
    nuevo = new Fila;
    nuevo->numero = nu;
    nuevo->siguiente = NULL;
    if (inicial == NULL) {
        inicial = nuevo;
        final = nuevo;
    }
    else {
        nuevo->siguiente = inicial;
        inicial = nuevo;
    }
}

void retirar() {
    if (inicial == NULL) std::cout << "La fila está vacia" << std::endl;
    else {
        actual = inicial;
        while (actual->siguiente != NULL)
        {
            penultimo = actual;
            actual = actual->siguiente;
        }
        penultimo->siguiente = NULL;
        final = penultimo;
    }
}

void imprime() {
    Fila *aux;
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
    retirar();
    //imprime();
    retirar();
    //imprime();
    retirar();
    retirar();
    imprime();

    return 0;
}
