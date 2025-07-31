#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int maxLen = 0, l = 0, r = 0;
    std::map<int, int> m;
    while (r < n) {
        m[arr[r]]++;
        if (m.size() > 2) {
            m[arr[l]]--;
            if (m[arr[l]] == 0)
                m.erase(arr[l]);
            l++;
        }
        if (m.size() <= 2)
            maxLen = std::max(maxLen, r - l + 1);
        r++;
    }
    std::cout << maxLen << std::endl;

    return 0;
}
