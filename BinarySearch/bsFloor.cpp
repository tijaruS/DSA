#include <bits/stdc++.h>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int low = 0;
    int high = n - 1;
    int ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] <= k) {
            ans = arr[mid];
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
