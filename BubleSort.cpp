/*
    La idea es que los elementos menos densos (los menores) “floten” hacia la superficie
    La complejidad es de O(n^2)
*/
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>

void bubbleSort(int lista[], int tamano) {
    for (int i = 0; i < tamano-1; i++) {
        for (int j = 0; j < tamano-i-1; j++) {
            if (lista[j] > lista[j+1]) {
                int aux = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = aux;
            }
        }
    }
}

int main() {
    int arreglo[] = {15, 35, 5, 723, 9, 114, 13, 155, 1, 19};
    bubbleSort(arreglo, 10);
    for (int k = 0; k < 10; k++)
        {
            std::cout<< arreglo[k]<<" ";
        }
    return 0;
}
