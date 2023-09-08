#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

struct Resultado {
    int valorOptimo;
    std::vector<int> elementosSeleccionados;
};

struct Elemento {
    int valor;
    int peso;
    double ratio; // Valor por unidad de peso (utilizado para tomar decisiones)
};

bool compararPorRatio(const Elemento &a, const Elemento &b) {
    return a.ratio > b.ratio;
}

// Solucion sin recursion
// Este muestra la ganancia optima y que elementos se seleccionarion
int knapsack(std::vector<int> &valores, std::vector<int> &pesos, int capacidad, std::vector<int> &seleccionados) {
    int n = valores.size();
    std::vector<std::vector<int>> K(n+1, std::vector<int>(capacidad+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacidad; w++) {
            K[i][w] = K[i - 1][w];
            if (pesos[i - 1] <= w) {
                int val = K[i - 1][w - pesos[i-1]] + valores[i-1];
                if (val > K[i][w]) {
                    K[i][w] = val;
                }
            }
        }
    }

    // Recuperar los elementos seleccionados
    int i = n;
    int j = capacidad;
    while (i > 0 && j > 0) {
        if (K[i][j] != K[i - 1][j]) {
            seleccionados.push_back(valores[i - 1]); // Agregar el valor de valores
            j -= pesos[i - 1];
        }
        i--;
    }
    return K[n][capacidad];
}

// Solucion recursiva
/* Solo muestra la ganancia optima
*/
int knapsack(std::vector<int> &valores, std::vector<int> &pesos, int capacidad, int n) {
    if (n == 0 || capacidad == 0) {
        return 0;
    }

    if (pesos[n - 1] > capacidad) {
        return knapsack(valores, pesos, capacidad, n - 1);
    } else {
        return std::max(valores[n - 1] + knapsack(valores, pesos, capacidad - pesos[n - 1], n - 1),
                        knapsack(valores, pesos, capacidad, n - 1));
    }
}

// Es igual que el recursivo pero este si recuerda que elementos se seleccionaron
Resultado knapsackMem(std::vector<int> &valores, std::vector<int> &pesos, int capacidad, int n) {
    if (n == 0 || capacidad == 0) {
        Resultado resultado;
        resultado.valorOptimo = 0;
        return resultado;
    }

    if (pesos[n - 1] > capacidad) {
        return knapsackMem(valores, pesos, capacidad, n - 1);
    } else {
        // Calculemos los resultados para ambas opciones
        Resultado sinIncluir = knapsackMem(valores, pesos, capacidad, n - 1);
        Resultado incluir = knapsackMem(valores, pesos, capacidad - pesos[n - 1], n - 1);
        incluir.valorOptimo += valores[n - 1];

        // Comparemos los resultados y elijamos la mejor opción
        if (incluir.valorOptimo > sinIncluir.valorOptimo) {
            incluir.elementosSeleccionados.push_back(valores[n - 1]); // Agregar elemento seleccionado
            return incluir;
        } else {
            return sinIncluir;
        }
    }
}

// Con divide y venceras
Resultado knapsack(std::vector<int> &valores, std::vector<int> &pesos, int capacidad, int inicio, int fin) {
    if (inicio > fin) {
        Resultado resultado;
        resultado.valorOptimo = 0;
        return resultado;
    }

    int mitad = (inicio + fin) / 2;

    // Resolver el problema para la mitad izquierda
    Resultado izquierda = knapsack(valores, pesos, capacidad, inicio, mitad);

    // Resolver el problema para la mitad derecha
    Resultado derecha = knapsack(valores, pesos, capacidad, mitad + 1, fin);

    // Combinar las soluciones de ambas mitades
    int capacidadRestante = capacidad;
    Resultado combinado;

    for (int i = inicio; i <= fin; i++) {
        capacidadRestante -= pesos[i];
        if (capacidadRestante >= 0) {
            combinado.valorOptimo += valores[i];
            combinado.elementosSeleccionados.push_back(valores[i]);
        } else {
            break; // No se pueden incluir más elementos
        }
    }

    // Elegir la mejor solución entre izquierda, derecha y combinado
    if (combinado.valorOptimo > izquierda.valorOptimo && combinado.valorOptimo > derecha.valorOptimo) {
        return combinado;
    } else if (izquierda.valorOptimo > derecha.valorOptimo) {
        return izquierda;
    } else {
        return derecha;
    }
}

// Con backtracking
Resultado knapsackBacktracking(std::vector<int> &valores, std::vector<int> &pesos, int capacidad, int indice, int valorActual, int pesoActual, std::vector<int> &seleccionados) {
    int n = valores.size();

    if (indice == n || pesoActual == capacidad) {
        Resultado resultado;
        resultado.valorOptimo = valorActual;
        resultado.elementosSeleccionados = seleccionados;
        return resultado;
    }

    // Caso en el que no se selecciona el elemento actual
    Resultado sinSeleccionar = knapsackBacktracking(valores, pesos, capacidad, indice + 1, valorActual, pesoActual, seleccionados);

    // Caso en el que se selecciona el elemento actual
    if (pesoActual + pesos[indice] <= capacidad) {
        seleccionados.push_back(valores[indice]);
        Resultado seleccionar = knapsackBacktracking(valores, pesos, capacidad, indice + 1, valorActual + valores[indice], pesoActual + pesos[indice], seleccionados);
        seleccionados.pop_back(); // Deshacer la selección

        // Comparar los resultados de seleccionar y sinSeleccionar
        if (seleccionar.valorOptimo > sinSeleccionar.valorOptimo) {
            return seleccionar;
        }
    }

    return sinSeleccionar;
}

// Con BranchAndBound
Resultado knapsackBranchAndBound(std::vector<int> &valores, std::vector<int> &pesos, int capacidad) {
    int n = valores.size();
    std::vector<Elemento> elementos(n);

    for (int i = 0; i < n; i++) {
        elementos[i].valor = valores[i];
        elementos[i].peso = pesos[i];
        elementos[i].ratio = static_cast<double>(valores[i]) / pesos[i];
    }

    // Ordenar elementos en orden no creciente de ratio (valor por unidad de peso)
    std::sort(elementos.begin(), elementos.end(), compararPorRatio);

    Resultado mejorResultado;
    mejorResultado.valorOptimo = 0;
    mejorResultado.elementosSeleccionados = std::vector<int>(n, 0);

    std::vector<int> solucionActual(n, 0);
    int valorActual = 0;
    int pesoActual = 0;
    int indice = 0;

    while (indice < n) {
        if (pesoActual + elementos[indice].peso <= capacidad) {
            solucionActual[indice] = 1; // Seleccionar el elemento
            valorActual += elementos[indice].valor;
            pesoActual += elementos[indice].peso;
        } else {
            solucionActual[indice] = 0; // No seleccionar el elemento
        }

        // Actualizar el mejor resultado si es necesario
        if (valorActual > mejorResultado.valorOptimo) {
            mejorResultado.valorOptimo = valorActual;
            mejorResultado.elementosSeleccionados = solucionActual;
        }

        // Calcular la cota (bound) para la siguiente rama
        int capacidadRestante = capacidad - pesoActual;
        double cota = valorActual + (capacidadRestante * elementos[indice].ratio);

        // Si la cota es menor que el valor óptimo actual, podamos esta rama
        if (cota < mejorResultado.valorOptimo) {
            break;
        }

        indice++;
    }

    return mejorResultado;
}

int main() {
    int n = 3, w = 3;
    std::vector<int> valores = {1, 2, 3};
    std::vector<int> pesos = {4, 5, 1};
    std::vector<int> seleccionados;
    int total = knapsack(valores, pesos, w, n);
    std::cout << total << " : ";
    //for (int i: seleccionados) {
    //    std::cout << i << " ";
    //}
    std::cout << std::endl;
    return 0;
}
