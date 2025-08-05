#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] < 9) {
            arr[i]++;
            break;
        }
        arr[i] = 0;
    }
    arr.insert(arr.begin(), 1);
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
