#include <bits/stdc++.h>
int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int ans = -1;
    if (n == 1)
        ans = arr[0];
    if (arr[0] != arr[1])
        ans = arr[0];
    if (arr[n - 1] != arr[n - 2])
        ans = arr[n - 1];
    int low = 1;
    int high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
            ans = arr[mid];
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) ||
            (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
            low = mid + 1;
        else
            high = mid - 1;
    }
    std::cout << ans << std::endl;
    return 0;
}
