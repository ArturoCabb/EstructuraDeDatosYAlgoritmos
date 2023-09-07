#include <iostream>
#include <vector>
#include <string>

long long prhf(std::string S) {
    int n = S.length();
    int p = 31;
    int m = 1e9 + 9;
    long long valorHash = 0;
    long long potencia = 1;
    for (int i = 0; i < n; i++) {
        valorHash = (valorHash + (S[i] - 'a' + 1) * potencia) % m;
        potencia = (potencia * p) % m;
    }
    return valorHash;
}

int main() {
    std::string cadena = "hola";
    std::cout << prhf(cadena) << std::endl;
    return 0;
}