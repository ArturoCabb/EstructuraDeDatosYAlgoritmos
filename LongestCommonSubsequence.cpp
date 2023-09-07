#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int longestCommonSubsequence(std::string cadena1, std::string cadena2) {
    int longS1 = cadena1.length(), longS2 = cadena2.length();
    std::vector<std::vector<int>> LCS(longS1 + 1, std::vector<int>(longS2 + 1));

    for (int i = 0; i <= longS1; i++) {
        for (int j = 0; j <= longS2; j++) {
            if (i == 0 || j == 0) {
                LCS[i][j] = 0;
            } else if (cadena1[i - 1] == cadena2[j - 1]) {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            } else {
                LCS[i][j] = std::max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }

    return LCS[longS1][longS2];
}

int longestCommonSubsequence(std::string cadena1, std::string cadena2, std::string &lcs) {
    int longS1 = cadena1.length(), longS2 = cadena2.length();
    std::vector<std::vector<int>> LCS(longS1 + 1, std::vector<int>(longS2 + 1));

    for (int i = 0; i <= longS1; i++) {
        for (int j = 0; j <= longS2; j++) {
            if (i == 0 || j == 0) {
                LCS[i][j] = 0;
            } else if (cadena1[i - 1] == cadena2[j - 1]) {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            } else {
                LCS[i][j] = std::max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }

    // Recuperar la subsecuencia común
    int i = longS1, j = longS2;
    while (i > 0 && j > 0) {
        if (cadena1[i - 1] == cadena2[j - 1]) {
            lcs = cadena1[i - 1] + lcs; // Agregar el carácter a la subsecuencia
            i--;
            j--;
        } else if (LCS[i - 1][j] > LCS[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return LCS[longS1][longS2];
}

int main() {
    std::string n = "waerbkhdf", m = "xabydzf";
    std::cout << longestCommonSubsequence(n, m) << std::endl;
    return 0;
}
