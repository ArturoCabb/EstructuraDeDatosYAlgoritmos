#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct Lista {
    int numero;
    Lista *siguiente = nullptr;
} *inicial;

void insertarFinal(int nu) {
    Lista *nuevo = new Lista;
    nuevo->numero = nu;
    if (inicial == nullptr)
        inicial = nuevo;
    else {
        Lista *actual = inicial;
        while (actual->siguiente != nullptr)
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

void eliminar(int nu)
{
    if (inicial == nullptr)
        std::cout << "No hay elementos para eliminar" << std::endl;
    else {
        Lista *actual = inicial;
        Lista *eliminar = nullptr;
        while (actual != nullptr) {
            if (actual->numero == nu) {
                eliminar = actual;
                inicial = inicial->siguiente;
                actual = inicial;
                delete eliminar;
            }
            else {
                if (actual->siguiente != nullptr && actual->siguiente->numero == nu) {
                    eliminar = actual->siguiente;
                    actual->siguiente = eliminar->siguiente;
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
    Lista *aux = inicial;
    while (aux != nullptr) {
        std::cout << aux->numero << std::endl;
        aux = aux->siguiente;
    }
}

int main() {
    insertarFinal(5);
    insertarFinal(10);
    insertarFinal(2);
    eliminar(2);
    imprime();
    
    return 0;
}
