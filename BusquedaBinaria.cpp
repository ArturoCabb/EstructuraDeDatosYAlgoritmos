/*
    Basado en el diseño, divide y vencerás
    Tiene un costo de O(log(n))
*/

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>

int busquedaBinaria(int E[], int primero, int ultimo, int K) {
    int indice;
    if (ultimo < primero) indice = -1;
    else {
        int medio = (primero + ultimo) / 2;
        if (K == E[medio])
            indice = medio;
        else if (K < E[medio])
            indice = busquedaBinaria(E, primero, medio-1, K);
        else
            indice = busquedaBinaria(E, medio+1, ultimo, K);
    }
    return indice;
}

int main() {
    int arreglo[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int resultado = busquedaBinaria(arreglo, 0, 10, 11);
    std::cout << resultado << std::endl;
    return 0;
}
