#include <bits/stdc++.h>

int main() {
    int n, k;

    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int maxLen = 0, l = 0, r = 0, zeros = 0;
    while (r < n) {
        if (arr[r] == 0)
            zeros++;
        if (zeros > k) {
            if (arr[l] == 0)
                zeros--;
            l++;
        }
        if (zeros <= k) {
            maxLen = std::max(maxLen, r - l + 1);
        }
        r++;
    }
    std::cout << maxLen << std::endl;

    return 0;
}
