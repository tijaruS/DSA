#include <bits/stdc++.h>

std::vector<int> sieve(1e7 + 1, 0);
int main() {
    int n;
    std::cin >> n;

    for (int i = 2; i * i <= n; i++) {
        if (sieve[i] == 0)
            for (long long j = 1LL * i * i; j <= n; j += i) {
                sieve[j] = 1;
            }
    }
    for (int i = 2; i <= n; i++) {
        if (sieve[i] == 0)
            std::cout << i << ' ';
    }
    std::cout << std::endl;
    // INFO: TC- O(nloglog(n))- prime harmonic series
    return 0;
}
