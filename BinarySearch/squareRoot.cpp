#include <bits/stdc++.h>
int main() {
    int n;
    std::cin >> n;

    int low = 1;
    int high = n;
    int ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        long long square = mid * mid;
        if (square <= n) {
            ans = mid;
            low = mid + 1;

        } else
            high = mid - 1;
    }
    std::cout << ans << std::endl;
    return 0;
}
