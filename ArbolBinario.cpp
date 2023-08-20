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
    
    NodoArbol* buscar(int dato, NodoArbol *r) {
        if (r == nullptr) return nullptr;
        else if (dato < r->dato)
            return buscar(dato, r->izquierdo);
        else if (dato > r->dato)
            return buscar(dato, r->derecho);
        else
            return r;
    }

    NodoArbol* eliminar(int d, NodoArbol *r)
    {
        // Buscamos el elemento(numero)
        bool SiEncontro = false;
        if (r == nullptr)
        {
            std::cout <<"El Arbol Binario Esta limpio !"<< std::endl;
            return nullptr;
        }

        NodoArbol *NoHo;
        NodoArbol *PadreAB;
        NoHo = r;

        while (NoHo != NULL)
        {
            if (NoHo->dato == d)
            {
                SiEncontro = true;
                break;
            }
            else
            {
                PadreAB = NoHo;
                if (d > NoHo->dato)
                    NoHo = NoHo->derecho;
                else
                    NoHo = NoHo->izquierdo;
            }
        }
        if (!SiEncontro)
        {
            std::cout <<"Dato no se encontro" << std::endl;
            return r;
        }

        // casos:
        // 1. Estamos eliminando un nodo hoja
        // 2. Estamos eliminando un nodo con un solo hijo
        // 3. estamos eliminando un nodo con 2 hijos
        // Nodo con uno de los hijos

        if ((NoHo->izquierdo == NULL && NoHo->derecho != NULL) || (NoHo->izquierdo != NULL && NoHo->derecho == NULL))
        {
            if (NoHo->izquierdo == NULL && NoHo->derecho != NULL)
            {
                if (PadreAB->izquierdo == NoHo)
                {
                    PadreAB->izquierdo = NoHo->derecho;
                    delete NoHo;
                }
                else
                {
                    PadreAB->derecho = NoHo->derecho;
                    delete NoHo;
                }
            }
            else // izquierdo hijo esté presente, no hay hijo derecho.
            {
                if (PadreAB->izquierdo == NoHo)
                {
                    PadreAB->izquierdo = NoHo->izquierdo;
                    delete NoHo;
                }
                else
                {
                    PadreAB->derecho = NoHo->izquierdo;
                    delete NoHo;
                }
            }
            return r;
        }
        // Nodo u hoja
        if (NoHo->izquierdo == NULL && NoHo->derecho == NULL)
        {
            if (PadreAB->izquierdo == NoHo)
                PadreAB->izquierdo = NULL;
            else
                PadreAB->derecho = NULL;
            delete NoHo;
            return r;
        }

        // Nodo con 2 hijos
        //  reemplazar el nodo con menor valor en el subárbol derecho
        if (NoHo->izquierdo != NULL && NoHo->derecho != NULL)
        {
            NodoArbol *chkr;
            chkr = NoHo->derecho;
            if ((chkr->izquierdo == NULL) && (chkr->derecho == NULL))
            {
                NoHo = chkr;
                delete chkr;
                NoHo->derecho = NULL;
            }
            else // Si hijo derecho tiene hijos
            {
                // si es hijo derecho del nodo tiene un hijo izquierdo
                // Mover todo el camino a la izquierdo para localizar elemento más pequeño
                if ((NoHo->derecho)->izquierdo != NULL)
                {
                    NodoArbol *lNoHo;
                    NodoArbol *lNoHop;
                    lNoHop = NoHo->derecho;
                    lNoHo = (NoHo->derecho)->izquierdo;
                    while (lNoHo->izquierdo != NULL)
                    {
                        lNoHop = lNoHo;
                        lNoHo = lNoHo->izquierdo;
                    }
                    NoHo->dato = lNoHo->dato;
                    delete lNoHo;
                    lNoHop->izquierdo = NULL;
                }
                else
                {
                    NodoArbol *Temporal;
                    Temporal = NoHo->derecho;
                    NoHo->dato = Temporal->dato;
                    NoHo->derecho = Temporal->derecho;
                    delete Temporal;
                }
            }
            return r;
        }
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
    //int dato = arbol.buscar(160, arbol.raiz)->dato;
    //std::cout << dato << std::endl;
    //std::cout << "\n\n Numero de Padres  :  " << arbol.noPadre(arbol.raiz) << std::endl << std::endl;
    //arbol.topView(arbol.raiz);
}
