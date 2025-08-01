#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    while (n--) {
        for (int i = 0; i < n; i++) {
            if (arr[i] > arr[i + 1])
                std::swap(arr[i], arr[i + 1]);
        }
    }
    for (auto it : arr) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;

    return 0;
}
