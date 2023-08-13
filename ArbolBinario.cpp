/*
    Cada nodo es mayor que la información de cada uno de los nodos que están en su subárbol izquierdo y menor que la almacenada en los nodos que están en su subárbol derecho.
    Se puede buscar, insertar y eliminar

    Falta la funcion de eliminar
*/

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <map>

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

class ArbolBinario {
    public:
    NodoArbol *raiz = nullptr;

    public:
    NodoArbol* crearArbolPie(int dato, NodoArbol *r) {
        if(r == nullptr)
            r = new NodoArbol(dato);
        else if (dato < r->dato)
            r->izquierdo = crearArbolPie(dato ,r->izquierdo);
        else if (dato > r->dato)
            r->derecho = crearArbolPie(dato, r->derecho);
        return r;
    }
    NodoArbol* eliminar(int dato, NodoArbol *r) {
        if( r == nullptr) return nullptr;
        else {
            if (dato < r->dato)
                r = eliminar(dato, r->izquierdo);
            else if (dato > r->dato)
                r = eliminar(dato, r->derecho);
            else {
                if ( r->izquierdo && r->derecho == nullptr) delete(r);
                else if (cantidadNodos(r) == 1){
                    if (r->izquierdo)
                        r = r->izquierdo;
                    else
                        r = r->derecho;
                }
                else {
                    NodoArbol *aux = r->izquierdo;
                    while (aux->derecho != nullptr)
                        aux = aux->derecho;
                    r->dato = aux->dato;
                    r = eliminar(aux->dato, r->izquierdo);
                }
            }
        }
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

    int cantidadNodos(NodoArbol *r) {
        if ( r == nullptr) return 0;
        else
            return 1 + cantidadNodos(r->izquierdo) + cantidadNodos(r->derecho);
    }

    int cantidadHojas(NodoArbol *r) {
        if (r == nullptr) return 0;
        if (r->izquierdo && r->derecho == nullptr) return 2;
        else
            return cantidadHojas(r->izquierdo) + cantidadHojas(r->derecho);
    }

    int noPadre(NodoArbol *r) {
        if (r == nullptr) return 0;
        if (r->izquierdo && r->derecho == nullptr) return 0;
        else
            return noPadre(r->izquierdo) + 1 + noPadre(r->derecho);
    }

    int altura(NodoArbol *r) {
        if (r == nullptr) return -1;
        else {
            int hi = altura(r->izquierdo);
            int hd = altura(r->derecho);
            if ( hi > hd) return 1+ hi;
            else return 1 + hd;
        }
    }

    void topView1(NodoArbol *r, std::map<int, std::pair<int, int> >& m, int distancia, int nivel) {
        if (r == nullptr) return;

        if (m.count(distancia) == 0 || m[distancia].second > nivel)
            m[distancia] = std::make_pair(r->dato, nivel);

        topView1(r->izquierdo, m, distancia-1, nivel+1);
        topView1(r->izquierdo, m, distancia+1, nivel-1);
    }

    void topView(NodoArbol *r){
	    std::map<int, std::pair<int, int> > m;
	    if (r == NULL) return;
	    else
	    	topView1(r, m, 0, 0);
	    for (auto i : m)
	    	std::cout << i.second.first << " ";
    }
};

int main() {
    ArbolBinario arbol;
    arbol.raiz = arbol.crearArbolPie(90, arbol.raiz);
    arbol.raiz = arbol.crearArbolPie(100, arbol.raiz);
    arbol.raiz = arbol.crearArbolPie(150, arbol.raiz);
    arbol.raiz = arbol.crearArbolPie(160, arbol.raiz);
    arbol.raiz = arbol.crearArbolPie(170, arbol.raiz);
    arbol.raiz = arbol.eliminar(150, arbol.raiz);
    arbol.verArbol(0, arbol.raiz);
    //std::cout << "\n\n Numero de Padres  :  " << arbol.noPadre(arbol.raiz) << std::endl << std::endl;
    //arbol.topView(arbol.raiz);
}
