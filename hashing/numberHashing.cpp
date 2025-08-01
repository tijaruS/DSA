#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::vector<int> hash(1e6);
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }
    int q;
    std::cin >> q;
    while (q--) {
        int num;
        std::cin >> num;
        std::cout << hash[num] << std::endl;
    }

    return 0;
}
