#include <bits/stdc++.h>
int main() {

    std::string a, b;
    std::cin >> a >> b;
    int len1 = a.length();
    int len2 = a.length();
    char c = b[len2 - 1];
    int ind;
    for (int i = 0; i < len1; i++) {
        if (a[i] == c)
            ind = i;
    }
    std::vector<std::vector<char>> ans(len2, std::vector<char>(len1, '.'));
    for (int j = 0; j < len2; j++) {
        ans[len1 - 1][j] = b[j];
    }
    for (int i = 0; i < len1; i++) {
        ans[i][ind] = a[i];
    }
    for (int i = 0; i < len2; i++) {
        for (int j = 0; j < len1; j++) {
            std::cout << ans[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
