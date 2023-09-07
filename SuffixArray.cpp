#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <vector>

std::vector<int> suffixArrayNaive(std::string S) {
    int n = S.length() + 1;
    std::vector<std::string> sa;
    std::vector<int> A(n);
    S = S + "$";
    for (int i = 0; i < n; i++)
        sa.push_back(S.substr(n-i-1, i+1));
    std::sort(sa.begin(), sa.end());
    for (int i = 0; i < n; i++)
        A[i] = n - sa[i].size() + 1;
    return A;
}

int main() {
    return 0;
}
