/*
    Arbol AVL
    En valor absoluto, entre la altura de su subárbol derecho e izquierdo es menor o igual a 1
    La diferencia entre las alturas de los subárboles se conoce como factor de equilibrio (FE), el cual se expresa como:
        FE = altura hijo derecho – altura hijo izquierdo
    El movimiento que se realiza para reinstaurar el balance se llama rotación y se hace sobre la raíz
    La altura está limitada a O (log(n))
    La inserción es del orden O (log(n))
*/

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>

class NodoArbol {
    public:
    int dato;
    int fe;
    NodoArbol *izquierdo;
    NodoArbol *derecho;

    NodoArbol(int dato) {
        this->dato = dato;
        this->fe = 0;
        izquierdo = nullptr;
        derecho = nullptr;
    }
};

class ArbolBalanceadoAVL {
    public:
    NodoArbol *raiz = nullptr;

    public:

    int altura(NodoArbol *r) {
        if (r == nullptr) return 0;
        else {
            int hi = altura(r->izquierdo);
            int hd = altura(r->derecho);
            if (hi > hd) return hi + 1;
            else return hd + 1;
        }
    }

    int factorEquilibrio(NodoArbol *r) {
        return altura(r->derecho) - altura(r->izquierdo);
    }

    NodoArbol* rotacionSimpleDerecha(NodoArbol *r) {
        NodoArbol *aux = r->izquierdo;
        r->izquierdo = aux->derecho;
        aux->derecho = r;
        aux->fe = factorEquilibrio(aux);
        return aux;
    }
    
    NodoArbol* rotacionSimpleIzquierda(NodoArbol *r) {
        NodoArbol *aux = r->derecho;
        r->derecho = aux->izquierdo;
        aux->izquierdo = r;
        aux->fe = factorEquilibrio(aux);
        return aux;
    }

    NodoArbol* dobleRotacionIzquierda(NodoArbol *r) {
        r->derecho = rotacionSimpleDerecha(r->derecho);
        return rotacionSimpleIzquierda(r);
    }

    NodoArbol* dobleRotacionDerecha(NodoArbol *r) {
        r->izquierdo = rotacionSimpleIzquierda(r->izquierdo);
        return rotacionSimpleDerecha(r);
    }

    NodoArbol* dobleRotacionIzquierdaDerecha(NodoArbol *r) {
        r->izquierdo = rotacionSimpleDerecha(r->izquierdo);
        return rotacionSimpleIzquierda(r);
    }

    NodoArbol* dobleRotacionDerechaIzquierda(NodoArbol *r) {
        r->derecho = rotacionSimpleIzquierda(r->derecho);
        return rotacionSimpleDerecha(r);
    }

    NodoArbol* crearArbolPie(int dato, NodoArbol *r) {
        if(r == nullptr)
            r = new NodoArbol(dato);
        else if (dato < r->dato) {
            r->izquierdo = crearArbolPie(dato, r->izquierdo);
            if (factorEquilibrio(r) == 2) {
                if (dato < r->izquierdo->dato){
                    r = rotacionSimpleIzquierda(r);
                }
                else{
                    r = dobleRotacionIzquierdaDerecha(r);
                }
            }
        }
        else if (dato > r->dato){
            r->derecho = crearArbolPie(dato, r->derecho);
            if (factorEquilibrio(r) ==-2) {
                if (dato > r->derecho->dato){
                    r = rotacionSimpleDerecha(r);
                }
                else{
                    r = dobleRotacionDerechaIzquierda(r);
                }
            }
        }
        r->fe = factorEquilibrio(r);
        return r;
    }

    void verArbol(int n, NodoArbol *r) {
        if (r == nullptr) return;

        verArbol(n+1, r->derecho);

        for (int i = 0; i<n; i++)
            std::cout << " ";
        
        std::cout << r->dato << std::endl;

        verArbol(n+1, r->izquierdo);
    }

    void preOrden(NodoArbol *r) {
        if (r != nullptr) {
            std::cout << r->dato << " ";
            preOrden(r->izquierdo);
            preOrden(r->derecho);
        }
    }

    void enOrden(NodoArbol *r) {
        if(r != nullptr) {
            enOrden(r->izquierdo);
            std::cout << r->dato << " ";
            enOrden(r->derecho);
        }
    }

    void postOrden(NodoArbol *r) {
        if (r != nullptr) {
            postOrden(r->izquierdo);
            postOrden(r->derecho);
            std::cout << r->dato << std::endl;
        }
    }
};

int main() {
    ArbolBalanceadoAVL arbol;
    arbol.raiz = arbol.crearArbolPie(100, arbol.raiz);
    arbol.raiz = arbol.crearArbolPie(150, arbol.raiz);
    arbol.raiz = arbol.crearArbolPie(90, arbol.raiz);
    arbol.raiz = arbol.crearArbolPie(160, arbol.raiz);
    arbol.raiz = arbol.crearArbolPie(170, arbol.raiz);
    //arbol.raiz = arbol.eliminar(arbol.raiz, 90);
    arbol.enOrden(arbol.raiz);
    std::cout << arbol.raiz->fe << std::endl;
    return 0;
}
