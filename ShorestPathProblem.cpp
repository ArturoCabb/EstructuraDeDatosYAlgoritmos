#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

struct DatosDelCamino {
    std::vector<int> Distancia;
    std::vector<int> Parent;
};

const int INFINITO = INT_MAX;

void floydWarshall(std::vector<std::vector<int>>& graph) {
    int n = graph.size();

    // Matriz de distancias mínimas inicializada con el grafo original
    std::vector<std::vector<int>> dist(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Algoritmo de Floyd-Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Si el camino pasando por el vértice k es más corto, actualiza la distancia
                if (dist[i][k] != INFINITO && dist[k][j] != INFINITO && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Imprimir la matriz de distancias mínimas
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INFINITO) {
                std::cout << "INFINITO ";
            } else {
                std::cout << dist[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

DatosDelCamino Dijkstra(std::vector<std::vector<int>> &grafo, int inicial, int final) {
    DatosDelCamino resultado;

    int N = grafo.size();
    std::vector<int> D(N, INFINITO);
    D[inicial] = 0;
    std::vector<int> parent(N, -1);
    // Vector que servirá para saber si se puede actualizar la distancia mínima de un nodo a otro, si es permanente (true) ya no se puede actualizar y significa que es la distancia óptima más corta.
    std::vector<bool> visitado(N, false);
    for (int i = 0; i < N - 1; ++i) {
        int actual = -1;
        // Buscamos el nodo no visitado con la distancia mínima actual
        for (int j = 0; j < N; j++) {
            if (!visitado[j] && (actual == -1 || D[j] < D[actual])) {
                actual = j;
            }
        }
        visitado[actual] = true;
        for (int v = 0; v < N; ++v) {
            if (!visitado[v] && grafo[actual][v] && D[actual] != INFINITO && D[actual] + grafo[actual][v] < D[v]) {
                D[v] = D[actual] + grafo[actual][v];
                parent[v] = actual;
            }
        }
    }
    resultado.Distancia = D;
    resultado.Parent = parent;
    return resultado;
}

int main() {
    return 0;
}
