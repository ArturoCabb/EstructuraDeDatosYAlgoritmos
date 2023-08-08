/*
    El nivel de un nodo: son los arcos que se deben de recorrer
    Altura de un nodo: el número de nodos recorridos hasya llegar a la hoja
    Altura de un árbol: Máxima altura
    Grado de un nodo: El número de hijos del nodo
    Grado de un árbol: Máximo de grado considerando todos los nodos

    Se puede buscar por profundidad (depth) o por anchura (breadth)
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct Arbol
{
    int valor;
    Arbol *izquierdo = NULL, *derecho = NULL;
} *raiz;

void insertar(int val) {
    Arbol *nuevo = new Arbol;
    nuevo->valor = val;
    
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;
}
