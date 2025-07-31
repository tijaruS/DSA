#include <bits/stdc++.h>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int maxSum = 0;
    int lSum = 0;
    int rSum = 0;
    for (int i = 0; i < k; i++) {
        lSum += arr[i];
    }
    maxSum = std::max(maxSum, lSum);
    int rInd = n - 1;
    for (int i = k - 1; i >= 0; i--) {
        lSum -= arr[i];
        rSum += arr[rInd];
        rInd--;
        maxSum = std::max(maxSum, lSum + rSum);
    }
    std::cout << maxSum << std::endl;

    return 0;
}
