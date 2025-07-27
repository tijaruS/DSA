#include <algorithm>
#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> ans;
    // INFO: TC=O(sqrt(n))
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
            if ((n / i) != i)
                ans.push_back(n / i);
        }
    }
    // INFO: TC: O(nlogn)
    std::sort(ans.begin(), ans.end());

    // INFO: TC: O(n)
    for (auto it : ans) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;

    return 0;
}
