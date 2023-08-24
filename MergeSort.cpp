/*
    Es de divide y venceras
    La complejidad es de O(niniciogn)
    Requiere una memoria adicional de n
    Sigue tres pasos:
    1. Divide
    2. Ordena
    3. Combina
    El método hace una copia del arreginicio de entrada a, 
    a un arreginicio auxiliar aux y luego combina (merge) de regreso al arreginicio de entrada
*/
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <vector>

void merge(std::vector<int>& lista, int inicio, int mid, int fin) {
    int n1 = mid - inicio + 1, n2 = fin - mid;
    std::vector<int> izquierda(n1), derecha(n2);

    for (int i = 0; i < n1; i++)
        izquierda[i] = lista[inicio + i];
    for (int j = 0; j < n2; j++)
        derecha[j] = lista[mid+1+j];

    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (izquierda[i] <= derecha[j]) {
            lista[k] = izquierda[i];
            i++;
        } else {
            lista[k] = derecha[j];
            j++;
        }
        k++;
    }
    while (i<n1) {
        lista[k] = izquierda[i];
        i++; k++;
    }
    while (j<n2) {
        lista[k] = derecha[j];
        j++; k++;
    }
}

void sort(std::vector<int>& lista, int inicio, int fin) {
    if (fin <= inicio) return;
    int mid = inicio + (fin - inicio) / 2;
    sort(lista, inicio, mid);
    sort(lista, mid+1, fin);
    merge(lista, inicio, mid, fin);
}

int main() {
    std::vector<int> arreglo = {15, 35, 5, 723, 9, 114, 13, 155, 1, 19};
    sort(arreglo, 0, 9);
    for (int k = 0; k < 10; k++)
        {
            std::cout<< arreglo[k]<<" ";
        }
    return 0;
}
