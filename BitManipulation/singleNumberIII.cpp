#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {

        std::cin >> arr[i];
    }
    std::map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[arr[i]]++;
    }
    std::vector<int> ans;
    for (auto it : m) {
        if (it.second == 1)
            ans.push_back(it.first);
    }
    for (auto it : ans) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;
    return 0;
}
