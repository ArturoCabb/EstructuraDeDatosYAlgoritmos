/*
    En cada paso, el elemento en cuestión queda colocado en el lugar correcto 
    del arreglo, de acuerdo a todos los elementos que están antes que él.
    • Cada elemento se compara con los que están arriba de él:
        • Si es mayor, ahí se queda.
        • Si es menor se mueve uno hacia arriba y se repite la operación hasta
        llegar a su posición correcta.
*/
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>

void insertionSort(int lista[], int tamano) {
    for (int i = 1; i < tamano; i++) {
        int actual = lista[i];
        int j = i - 1;
        while (j >= 0 && lista[j] > actual) {
            lista[j+1] = lista[j];
            j--;
        }
        lista[j+1] = actual;
    }
}

int main() {
    int arreglo[] = {15, 35, 5, 723, 9, 114, 13, 155, 1, 19};
    insertionSort(arreglo, 10);
    for (int k = 0; k < 10; k++)
        {
            std::cout<< arreglo[k]<<" ";
        }
    return 0;
}
