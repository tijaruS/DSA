#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int i = 0;
    while (i < n - 1) {
        auto it = std::min_element(arr.begin() + i, arr.end());
        int j = std::distance(arr.begin(), it);
        std::swap(arr[i], arr[j]);
        i++;
    }
    for (auto it : arr) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;

    return 0;
}
