#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    int cnt = 0;

    while (n > 0) {
        cnt++;
        n = n / 10;
    }
    // or we can use log of base 10 to find the count of digits
    // cnt = (int)(log10(n) + 1);

    std::cout << cnt << std::endl;
    return 0;
    //  INFO: TC- O(log10(n)
}
