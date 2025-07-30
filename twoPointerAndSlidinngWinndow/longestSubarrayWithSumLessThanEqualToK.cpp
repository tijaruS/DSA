#include <bits/stdc++.h>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int sum = 0;
    int l = 0;
    int r = 0;
    int ans = 0;
    while (r < n) {
        sum += arr[r];
        if (sum > k) {
            sum -= arr[l];
            l++;
        }
        if (sum <= k)
            ans = std::max(ans, r - l + 1);
        r++;
    }
    std::cout << ans << std::endl;
    return 0;
}
