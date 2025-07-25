#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int low = 0;
    int high = n - 1;
    int minel = INT_MAX;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[low] <= arr[mid]) {
            minel = std::min(minel, arr[low]);
            low = mid + 1;
        } else {
            minel = std::min(minel, arr[mid]);
            high = mid - 1;
        }
    }
    std::cout << minel << std::endl;

    return 0;
}
