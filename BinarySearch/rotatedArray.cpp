#include <bits/stdc++.h>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int ans = -1;
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == k)
            ans = mid;
        // left sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        // right sorted
        else {
            if (arr[mid] <= k && k <= arr[high]) {
                low = mid + 1;
            } else
                high = mid - 1;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
