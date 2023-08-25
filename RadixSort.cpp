/*
    Tiene una dificultad de O(nlogn)
*/
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <vector>

int getMax(std::vector<int>& arr) {
    int tam = arr.size();
    int max = arr[0];
    for (int i = 1; i < tam; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countSort(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(std::vector<int>& arr) {
    int max = getMax(arr);

    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(arr, exp);
}

int main() {
    std::vector arreglo = {15, 35, 5, 723, 9, 114, 13, 155, 1, 19};
    radixSort(arreglo);
    for (int k = 0; k < 10; k++)
        {
            std::cout<< arreglo[k]<<" ";
        }
    return 0;
}
