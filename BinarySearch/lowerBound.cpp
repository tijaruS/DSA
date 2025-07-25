#include <bits/stdc++.h>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int low = 0;
    int ans = n;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= k) {
            ans = mid;
            high = mid - 1;
        }
        if (arr[mid] < k) {
            low = mid + 1;
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
