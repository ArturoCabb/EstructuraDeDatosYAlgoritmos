/*
    El nivel de un nodo: son los arcos que se deben de recorrer
    Altura de un nodo: el número de nodos recorridos hasya llegar a la hoja
    Altura de un árbol: Máxima altura
    Grado de un nodo: El número de hijos del nodo
    Grado de un árbol: Máximo de grado considerando todos los nodos

    Se puede buscar por profundidad (depth) o por anchura (breadth)

    Los recorridos que existen son:
    1. preorden: de la raiz al izquierdo y luego derecho
    2. inorden: del elemento de la izquierda a la derecha
    3. Postorden: del izquierdo final al redecho final y así avanzando hacia 
    arriba por todos los nodos
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class NodoArbol {
    public:
    int dato;
    NodoArbol *izquierdo;
    NodoArbol *derecho;

    NodoArbol(int dato) {
        this->dato = dato;
        izquierdo = nullptr;
        derecho = nullptr;
    }
};

class Arbol {
    public:
    NodoArbol *raiz = nullptr;

    public:
    NodoArbol* creaArbolPie() {
        int dato, respuesta;
        std::cout << "Dato del nodo ";
        std::cin >> dato;

        NodoArbol *pie = new NodoArbol(dato);
        std::cout << "¿El nodo " << dato << " tiene hijo izquierdo?";
        std::cin >> respuesta;
        if (respuesta == 1)
            pie->izquierdo = creaArbolPie();
        std::cout << "¿El nodo " << dato << " tiene hijo derecho?";
        std::cin >> respuesta;
        if (respuesta == 1)
            pie->derecho = creaArbolPie();
        return pie;
    }

    void crearArbol() {
        raiz = creaArbolPie();
    }

    void preorden(NodoArbol *r) {
        if (r != nullptr) {
            std::cout << r->dato << " ";
            preorden(r->izquierdo);
            preorden(r->derecho);
        }
    }

    void inorden(NodoArbol *r) {
        if (r != nullptr) {
            inorden(r->izquierdo);
            std::cout << r->dato;
            inorden(r->derecho);
        }
    }

    void postorden(NodoArbol *r) {
        if (r != nullptr) {
            postorden(r->izquierdo);
            postorden(r->derecho);
            std::cout << r->dato;
        }
    }
};

int main() {
    Arbol miArbol;
    miArbol.crearArbol();
    std::cout << "Preorden" << std::endl;
    miArbol.preorden(miArbol.raiz);
    std::cout << std::endl;
    std::cout << "Inorden" << std::endl;
    miArbol.inorden(miArbol.raiz);
    std::cout << std::endl;
    std::cout << "Postorden" << std::endl;
    miArbol.postorden(miArbol.raiz);
    std::cout << std::endl;
    return 0;
}
