#include <bits/stdc++.h>

int main() {
    int mask;
    std::cin >> mask;
    for (int subset = mask; subset; subset = (mask & (subset - 1)))
        std::cout << subset << std::endl;

    return 0;
}
