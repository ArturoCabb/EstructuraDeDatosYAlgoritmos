/*
    Costo del algoritmo O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>

int busquedaSecuencial(int E[], int n, int K) {
    for (int indice = 0; indice < n; indice++) {
        if (K == E[indice]) {
            return indice;
        }
    }
    return -1;
}

int main() {

    int arreglo[6];
    arreglo[0] = 1;
    arreglo[1] = 10;
    arreglo[2] = 12;
    arreglo[3] = 13;
    arreglo[4] = 14;
    arreglo[5] = 15;

    int ubicacion = busquedaSecuencial(arreglo, 6, 14);
    std::cout << ubicacion << std::endl;
    return 0;
}