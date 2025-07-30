#include <bits/stdc++.h>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        int zeros = 0;
        for (int j = i; j < n; j++) {
            if (arr[j] == 0)
                zeros++;
            if (zeros <= k) {
                maxLen = std::max(maxLen, j - i + 1);
            } else
                break;
        }
    }
    std::cout << maxLen << std::endl;

    return 0;
}
