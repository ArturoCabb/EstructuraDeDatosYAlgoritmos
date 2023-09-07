/*
    • La idea principal es que en el momento en que se encuentre
        que una solución parcial no puede ser la solución buscada, se
        detiene el proceso (a esto se le llama poda).
    • Un problema de optimización es aquel en que se quiere
        encontrar la solución que maximice o minimice una función,
        muchas veces sujeta a ciertas restricciones.
    • Es equivalente a encontrar el máximo o el mínimo de una
        función continua usando:
    • Cálculo diferencial, derivadas parciales o Multiplicadores de Lagrange.
    • Solución factible: es aquella que cumple con todas las
        restricciones que tenga el problema.
    • Solución óptima: es la solución factible que maximiza o minimiza
        la función, dependiendo de lo que se busque.
    • Función objetivo: es la función que se quiere maximizar o
        minimizar.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

const int INFINITO = INT_MAX;

void BranchAndBound(std::vector<std::vector<int>>& graph, int n, int start) {
    std::vector<int> sinVisitar;
    for (int i = 0; i < n; i++) {
        if (i != start)
            sinVisitar.push_back(i);
    }

    int minCost = INFINITO;
    do
    {
        int costoActual = 0;
        int vertexActual = start;
        for (int i = 0; i < n - 1; i++) {
            int vertexSiguiente = sinVisitar[i];
            costoActual += graph[vertexActual][vertexSiguiente];
        }
    } while (std::next_permutation(sinVisitar.begin(), sinVisitar.end()));
    
}

int main() {
    return 0;
}
