/*
    La complejidad de este algoritmo es de O(n^2)
*/
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>

void selectionSort(int lista[], int tamano) {
    int minimo;
    for (int i = 0; i < tamano-1; i++) {
        minimo = i;
        for (int j = i+1; j < tamano; j++) {
            if (lista[j] < lista[minimo])
                minimo = j;
        }
        if (minimo != i) {
        int aux = lista[i];
        lista[i] = lista[minimo];
        lista[minimo] = aux;
        }
    }
}

int main() {
    int arreglo[] = {15, 35, 5, 723, 9, 114, 13, 155, 1, 19};
    selectionSort(arreglo, 10);
    for (int k = 0; k < 10; k++)
        {
            std::cout<< arreglo[k]<<" ";
        }
    return 0;
}