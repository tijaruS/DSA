#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> ans;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            ans.push_back(i);
        while (n % i == 0) {
            n = n / i;
        }
    }
    if (n != 1)
        ans.push_back(n);

    for (auto it : ans) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;
    return 0;
}
