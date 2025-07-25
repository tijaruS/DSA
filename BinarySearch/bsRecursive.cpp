#include <bits/stdc++.h>
int bs(std::vector<int> &arr, int low, int high, int target) {
    int mid = (low + high) / 2;
    if (low > high)
        return -1;
    if (arr[mid] == target)
        return mid;
    if (arr[mid] < target)
        return bs(arr, mid + 1, high, target);
    else
        return bs(arr, low, mid - 1, target);
}
int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int ans = bs(arr, 0, n - 1, k);

    std::cout << ans << std::endl;
    return 0;
}
