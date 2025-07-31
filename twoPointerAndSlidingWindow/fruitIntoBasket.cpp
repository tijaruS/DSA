#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        std::set<int> s;
        for (int j = i; j < n; j++) {
            s.insert(arr[j]);
            if (s.size() > 2)
                break;
            if (s.size() <= 2)
                maxLen = std::max(maxLen, j - i + 1);
        }
    }
    std::cout << maxLen << std::endl;

    return 0;
}
