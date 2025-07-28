#include <bits/stdc++.h>

int main() {
    std::vector<int> spf(1e5 + 1);
    for (int i = 0; i <= 1e5; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i <= 1e5; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= 1e5; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
    int q;
    std::cin >> q;
    while (q--) {
        int n;
        std::cin >> n;
        while (n != 1) {
            std::cout << spf[n] << ' ';
            n = n / spf[n];
        }
        std::cout << std::endl;
    }
    // INFO: TC- O(nloglog(n)+ q*log2(n))
    // INFO: SC- O(n)
    return 0;
}
