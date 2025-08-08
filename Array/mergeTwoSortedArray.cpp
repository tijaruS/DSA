#include <bits/stdc++.h>
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> arr1(n);
    for (int &i : arr1) {
        std::cin >> i;
    }
    std::vector<int> arr2(m);
    for (int &j : arr2) {
        std::cin >> j;
    }
    int i = 0, j = 0;
    std::vector<int> ans;
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {
            ans.push_back(arr1[i++]);
        } else
            ans.push_back(arr2[j++]);
    }
    while (i < n)
        ans.push_back(arr1[i++]);
    while (j < m)
        ans.push_back(arr2[j++]);
    for (int a : ans) {
        std::cout << a << ' ';
    }
    std::cout << std::endl;

    return 0;
}
