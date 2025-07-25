#include <algorithm>
#include <bits/stdc++.h>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    auto lit = std::lower_bound(arr.begin(), arr.end(), k);
    int lb = lit - arr.begin();
    int ub = std::upper_bound(arr.begin(), arr.end(), k) - arr.begin() - 1;
    if (lb == n || arr[lb] != k)
        std::cout << -1 << ' ' << -1 << std::endl;
    else
        std::cout << lb << ' ' << ub << std::endl;

    return 0;
}
