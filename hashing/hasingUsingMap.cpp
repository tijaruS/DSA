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
    int q;
    std::cin >> q;
    while (q--) {
        int num;
        std::cin >> num;
        std::cout << m[num] << std::endl;
    }

    return 0;
}
