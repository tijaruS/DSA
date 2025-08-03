#include <algorithm>
#include <bits/stdc++.h>
#include <utility>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int &x : arr) {
        std::cin >> x;
    }
    int ind = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            ind = i;
            break;
        }
    }
    if (ind == -1)
        std::reverse(arr.begin(), arr.end());
    else {
        for (int i = n - 1; i > ind; i--) {
            if (arr[i] > arr[ind]) {
                std::swap(arr[i], arr[ind]);
                break;
            }
        }
        std::reverse(arr.begin() + ind + 1, arr.end());
    }
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
