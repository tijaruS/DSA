#include <bits/stdc++.h>

int main() {
    double x;
    int n;
    std::cin >> x >> n;
    int m = n;

    int exp = std::abs(n);
    double base = x;
    double ans = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            ans = ans * base;
            exp -= 1;
        } else {
            base *= base;
            exp /= 2;
        }
    }
    if (m < 0)
        ans = 1.0 / ans;
    // INFO: TC- O(lon2(n))
    std::cout << ans << std::endl;
    return 0;
}
