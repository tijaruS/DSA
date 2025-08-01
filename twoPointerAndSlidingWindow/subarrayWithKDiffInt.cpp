#include <bits/stdc++.h>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        std::set<int> s;
        for (int j = i; j < n; j++) {
            s.insert(arr[j]);
            if (s.size() == k)
                cnt++;
            if (s.size() > k)
                break;
        }
    }
    std::cout << cnt << std::endl;

    return 0;
}
