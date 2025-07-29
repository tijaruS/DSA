#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int ans = 0;
    for (int bit = 0; bit <= 31; bit++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] & (1 << bit))
                cnt++;
        }
        if (cnt % 3 == 1)
            ans = ans | (1 << bit);
    }
    std::cout << ans << std::endl;

    return 0;
}
