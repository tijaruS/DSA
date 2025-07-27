#include <bits/stdc++.h>

int main() {
    int m;
    std::cin >> m;
    int cnt = 0;

    for (int i = 1; i * i <= m; i++) {
        if (m % i == 0) {
            cnt++;
            if ((m / i) != i)
                cnt++;
        }
    }
    if (cnt == 2)
        std::cout << "Prime Number" << std::endl;
    else
        std::cout << "No a Prime Number" << std::endl;

    return 0;
}
