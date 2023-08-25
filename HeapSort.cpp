/*
    Tiene una dificultad de O(nlogn)
*/
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <vector>

void heapify(std::vector<int>& arr, int n, int i) {
    int largo = i; // // Inicializar el valor mas grnade como la raiz
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    // Si el hijo izquierdo es más grande que la raiz
    if (left < n && arr[left] > arr[largo])
        largo = left;

    // Si el hijo derecho es m,ás grnade que la raiz o el hijo izquierdo
    if (right < n && arr[right] > arr[largo])
        largo = right;
    
    // Si el valor mas grnade no es la raiz
    if (largo != i) {
        std::swap(arr[i], arr[largo]);
        // Reorganizar el subarbol afectado
        heapify(arr, n, largo);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Construir un heap maxico (reorganizar el arreglo)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extraer elemento de heap uno por uno
    for (int i = n - 1; i > 0; i--) {
        // Mover la raiz actual al final
        std::swap(arr[0], arr[i]);
        // Llamar a heapify en el subárbol reducido
        heapify(arr, i, 0);
    }
}

int main() {
    std::vector arreglo = {15, 35, 5, 723, 9, 114, 13, 155, 1, 19};
    heapSort(arreglo);
    for (int k = 0; k < 10; k++)
        {
            std::cout<< arreglo[k]<<" ";
        }
    return 0;
}
