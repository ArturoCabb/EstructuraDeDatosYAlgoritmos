/*
    Utiliza una estructura de árbol:
    • La raíz es el inicio del problema.
    • Cada nivel está formado por los posibles valores que puede tomar una
        de las variables involucradas en el problema.
    • El último nivel del árbol contiene todas las posibles soluciones del
        espacio, por tal razón.
    • A este árbol se le conoce como “Árbol del espacio de estados”.
    • Lo va formando usando la regla “Primero Profundidad” (DFS).
*/

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <vector>

void backTracking(std::vector<int>& numeros, std::vector<int>& actual, std::vector<bool>& usado, std::vector<std::vector<int>>& resultado) {
    int tamano = numeros.size();
    if (actual.size() == tamano) {
        resultado.push_back(actual);
        return;
    }
    for (int i = 0; i < tamano; i++) {
        if (!usado[i]) {
            actual.push_back(numeros[i]);
            usado[i] = true;
            backTracking(numeros, actual, usado, resultado);
            actual.pop_back();
            usado[i] = false;
        }
    }
}

std::vector<std::vector<int>> permute(std::vector<int>& numeros) {
    std::vector<std::vector<int>> resultado;
    std::vector<int> actual;
    std::vector<bool> usado(numeros.size(), false);
    backTracking(numeros, actual, usado, resultado);
    return resultado;
}

int main() {
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> permutations = permute(nums);

    for (const auto& perm : permutations) {
        for (int num : perm) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
