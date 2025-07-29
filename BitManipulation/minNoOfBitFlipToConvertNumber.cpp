#include <bits/stdc++.h>

int main() {
    int a, b;
    std::cin >> a >> b;
    int m = a ^ b;
    std::cout << __builtin_popcount(m) << std::endl;
    int cnt = 0;
    for (int i = 0; i <= 31; i++) {
        if ((m & (1 << i)))
            cnt++;
    }
    std::cout << cnt << std::endl;
    std::cout << __builtin_clz(m) << std::endl;

    return 0;
}
