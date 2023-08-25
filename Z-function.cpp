/*
    La naive tiene una complejidad de O(n^2)
    y la memorizacipon es de O(n)
*/
#include <iostream>
#include <vector>
#include <string>

std::vector<int> ZNaive(const std::string S) {
    int n = S.length();
    std::vector<int> A(n, 0);
    for (int i = 1; i < n; i++)
        for (int j = i; j < n; j++)
            if (S[j] == S[j - i])
                A[i]++;
            else
                break;
    return A;
}

std::vector<int> calculateZFunction(const std::string& text) {
    int n = text.length();
    std::vector<int> Z(n, 0);
    int left = 0;
    int right = 0;

    for (int i = 1; i < n; i++) {
        if (i <= right) {
            Z[i] = std::min(right - i + 1, Z[i - left]);
        }

        while (i + Z[i] < n && text[Z[i]] == text[i + Z[i]]) {
            Z[i]++;
        }

        if (i + Z[i] - 1 > right) {
            left = i;
            right = i + Z[i] - 1;
        }
    }

    return Z;
}

int main() {
    std::string text = "aca$bacacabcaca";
    std::vector<int> zArray = calculateZFunction(text);

    std::cout << "Z-array: ";
    for (int value : zArray) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
