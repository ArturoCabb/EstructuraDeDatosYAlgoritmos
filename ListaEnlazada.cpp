#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct Lista {
    int numero;
    int edad;
    Lista *siguiente;
    Lista *anterior;
} *inicial, *final, *antes, *nuevo;

void insertar(int nu, int ed){
    nuevo = new Lista;
    nuevo->numero = nu;
    nuevo->edad = ed;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    if (inicial == NULL)
    {
        inicial = nuevo;
        antes = NULL;
        final = nuevo;
    }
    else {
        final->anterior = final;
    }
}

int main() {
    return 0;
}