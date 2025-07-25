#include <bits/stdc++.h>

int main() {
    int n, target;
    std::cin >> n >> target;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            ans = mid;
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= target && target <= arr[mid]) {
                high = mid - 1;
            } else
                low = mid + 1;
        } else if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low = low + 1;
            high = high - 1;
        } else {
            if (arr[mid] <= target && target <= arr[high]) {
                low = mid + 1;
            } else
                high = mid - 1;
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
