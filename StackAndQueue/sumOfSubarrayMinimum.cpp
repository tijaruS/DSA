#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    int mod = 1e9 + 7;
    std::vector<int> arr(n);
    for (int &a : arr) {
        std::cin >> a;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int min = arr[i];
        for (int j = i; j < n; j++) {
            if (arr[j] < min)
                min = arr[j];
            ans = (ans + min) % mod;
        }

        return 0;
    }
}
