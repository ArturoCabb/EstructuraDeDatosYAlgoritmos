/*
    La idea básica es:
    • Se van comparando los caracteres a partir de la posición i del texto con los
    del patrón.
    • Cuando uno no coincide, en el substring del patrón que se tiene antes de la
    no coincidencia, buscamos el máximo prefijo que al mismo tiempo sea
    sufijo de dicho substring.
    • Si no existe, no nos tenemos que regresar ni un carácter en el texto, sólo
    nos regresamos en el patrón a su posición inicial.
    • Si existe un prefijo que es sufijo, y la longitud de este prefijo es k,
    continuamos a partir de la posición i del texto, pero no tenemos que
    regresar a la posición 1 del patrón, sino a la posición 1+k.
    • Este proceso se hace tan hacia atrás como sea necesario, pudiendo llegar a
    iniciar el patrón en su posición 1

    La complejidad en el tiempo es de O(m + n) donde m es del patron y n es lonjitud de texto
*/
#include <iostream>
#include <vector>
#include <string>

std::vector<int> preProcesamiento(std::string patron) {
    int n = patron.length();
    std::vector<int> V(n, 0);
    V[0] = 0;
    int j = 0, i = 1;
    while (i < n) {
        if (patron[i] == patron[j]) {
            j ++;
            V[i] = j;
            i ++;
        }
        else {
            if (j == 0) {
                V[i] = 0;
                i ++;
            }
            else
                j = V[j-1];
        }
    }
    return V;
}

std::vector<int> KMP(std::string cadena, std::string patron) {
    std::vector<int> V = preProcesamiento(patron);
    int n = cadena.size(), m = patron.size();
    int posicion = 0; // Es donde inicia P en T
    int j = 0; // Indice en el patron
    int i = 0; // ïndice del texto
    std::vector<int> ubic;

    while (i < n) {
        if (cadena[i] == patron[j]) {
            j ++;
            i ++;
            if (j == m) {
                ubic.push_back(i-j);
            }
        }
        else {
            if (j == 0) {
                i++;
            } else {
                j = V[j-1];
            }
        }
    }
    return ubic;
}

int main() {
    std::string text = "bacacabcaca";
    std::string patron = "aca";
    std::vector<int> posicion = KMP(text, patron);
    for (int value : posicion) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}
