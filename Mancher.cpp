/*
    Palindromo más grande
    Tiene una complejidad de O(n)
    Se crea un string T agregando un carácter especial en medio de
    cada carácter original, además de uno al inicio y otro al final del string original, lo
    cual garantiza que el nuevo string T siempre tiene una longitud impar. El carácter
    que se agrega puede ser cualquier que no pertenezca al alfabeto del string
    analizado.
*/
#include <iostream>
#include <vector>
#include <string>

std::string procesamiento(std::string cadena) {
    std::string T = "";
    int tam = cadena.size();
    for (int i = 0; i < tam; i++)
        T += "|" + cadena[i];
    return T + "|";
}

void Manacher(std::string cadena) {
    if (cadena.size() == 0)
        std::cout << -1 << std::endl;
    else {
        std::string T = procesamiento(cadena);
        int N = T.size();
        std::vector<int> L(N);
        L[0] = 0;
        L[1] = 1;
        int maxLong = 0, maxCentro = 0;
        int C = 1, Ri = 0, Li = 0;
        bool expansion = false;
        for (int Ri = 2; Ri < N; Ri++) {
            int Li = C - (Ri - C);
            expansion = false;
            if (C + L[C] - Ri) {
                if (L[Li] < (C + L[C]) - Ri)
                    L[Ri] = L[Li];
                else if (L[Li] == (C + L[C]) - Ri && (C + L[C]) == N - 1)
                    L[Ri] = L[Li];
                else if (L[Li] == (C + L[C]) - Ri && (C + L[C]) < N - 1) {
                    L[Ri] = L[Li];
                    expansion = true;
                }
                else if (L[Li] > (C + L[C]) - Ri) {
                    L[Ri] = (C + L[C]) - Ri;
                    expansion = true;
                }
            }
            else {
                L[Ri] = 0;
                expansion = true;
            }
            if (expansion) {
                while ((Ri + L[Ri]) < N && (Ri - L[Ri]) > 0 && T[Ri + L[Ri] + 1] == T[Ri - L[Ri] - 1])
                    L[Ri]++;
            }
            if (Ri + L[Ri] > (C + L[C]))
                C = Ri;
            if (L[Ri] > maxLong)
                maxLong = L[Ri];
            maxCentro = Ri;
        }
        int posicionInicio = (maxCentro - maxLong) / 2;
        int posicionFinal = posicionInicio + maxLong;
        std::cout << posicionInicio + 1 << " " << posicionFinal << std::endl;
    }
}

int main() {
    std::string cadena = "cacbcac";
    Manacher(cadena);
    return 0;
}