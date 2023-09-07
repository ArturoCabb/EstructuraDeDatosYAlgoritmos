#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int longestCommonSubstring(std::string sUno, std::string sDos) {
    int lenS1 = sUno.length(), lenS2 = sDos.length();
    std::vector<std::vector<int>> LCS(lenS1 + 1, std::vector<int>(lenS2 + 1));
    int MAX = 0;

    for (int i = 1; i <= lenS1; i++) {
        for (int j = 1; j <= lenS2; j++) {
            if (sUno[i - 1] == sDos[j - 1]) {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
                if (LCS[i][j] > MAX) {
                    MAX = LCS[i][j];
                }
            } else {
                LCS[i][j] = 0;
            }
        }
    }
    return MAX;
}

std::vector<int> lCS(std::string sUno, std::string sDos) {
    int lenS1 = sUno.length(), lenS2 = sDos.length();
    std::vector<std::vector<int>> LCS(lenS1 + 1, std::vector<int>(lenS2 + 1));
    int MAX = 0, inicioCadena1 = -1, inicioCadena2 = -1;

    for (int i = 1; i <= lenS1; i++) {
        for (int j = 1; j <= lenS2; j++) {
            if (sUno[i - 1] == sDos[j - 1]) {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
                if (LCS[i][j] > MAX) {
                    MAX = LCS[i][j];
                    inicioCadena1 = i;
                    inicioCadena2 = j;
                }
            } else {
                LCS[i][j] = 0;
            }
        }
    }
    inicioCadena1 = inicioCadena1 - MAX;
    inicioCadena2 = inicioCadena2 - MAX;
    return {MAX, inicioCadena1, inicioCadena2};
}

int main()
{
    std::string sUno = "abcxabcdy", sDos = "cyabcdx";
    std::cout << longestCommonSubstring(sUno, sDos) << std::endl;
    return 0;
}
