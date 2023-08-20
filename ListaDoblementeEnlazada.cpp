#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct Lista {
    int numero;
    int edad;
    Lista *siguiente = nullptr, *anterior = nullptr;
} *inicial, *final, *nuevo;

void insertar(int nu, int ed){
    nuevo = new Lista;
    nuevo->numero = nu;
    nuevo->edad = ed;
    if (inicial == nullptr)
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

void eliminar(int nu) {
    if (inicial == nullptr) std::cout << "No hay elementos para eliminar" << std::endl;
    else {
        Lista *actual = inicial;
        Lista *eliminar = nullptr, *aux = nullptr;
        while (actual != nullptr) {
            if (actual->numero == nu) {
                eliminar = actual;
                inicial->siguiente = inicial->siguiente;
                inicial->anterior = inicial->anterior;
                actual = inicial;
                delete eliminar;
            }
            else {
                if (actual->siguiente != nullptr && actual->siguiente->numero == nu) {
                    eliminar = actual->siguiente;
                    actual->siguiente = eliminar->siguiente;
                    aux = actual->siguiente;
                    aux->anterior = actual;
                    delete eliminar;
                }
                else {
                    actual = actual->siguiente;
                }
            }
        }
    }
}

void imprime() {
    Lista *aux;
    aux = inicial;
    while (aux != nullptr) {
        std::cout << aux->numero << " tiene la edad de: " << aux->edad << std::endl;
        aux = aux->siguiente;
    }
}

int main() {
    insertar(5, 10);
    insertar(10, 20);
    insertar(2, 15);
    eliminar(10);
    imprime();

    return 0;
}