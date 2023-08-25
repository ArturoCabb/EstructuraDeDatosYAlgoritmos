/*
    Tiene el enfoque de divide y venceras
    En promedio tiene una eficiencia de O(nlogn)
    En el peor aso tiene una eficiencia de O(n^2)
*/
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>

int partition(int a[], int lo, int hi) {
    int i = lo, j = hi + 1;
    int v = a[lo]; // pivote
    while (true) {
        // mueve i a la derecha mientras a[i] < v
        // mueve j a la izquierda mientrras a[j] > v
        if (i>=j) break; // si se cruza termin
        // si no, intercambia los elementos a[i] y a[j]
    }
    v = a[j]; // Poner pivote en su posición
    return j; // con a[lo...j-1] <= a[j] <= a[j+1...hi]
}

void sort(int a[], int lo, int hi) {
    if (hi <= lo) return;
    int j = partition(a, lo, hi);
    // Ordenar parte izquierda a[lo..j-1]
    sort(a, lo, j-1);
    // ordenar a la derecha a[j+1..hi]
    sort(a, j+1, hi);
}

int main() {
    int arreglo[] = {15, 35, 5, 723, 9, 114, 13, 155, 1, 19};
    sort(arreglo, 0, 9);
    for (int k = 0; k < 10; k++)
        {
            std::cout<< arreglo[k]<<" ";
        }
    return 0;
}
