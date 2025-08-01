#include <bits/stdc++.h>

int main() {
    int n, sum;
    std::cin >> n >> sum;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int ssum = 0;
        for (int j = i; j < n; j++) {
            ssum += arr[j];
            if (ssum == sum)
                cnt++;
        }
    }
    std::cout << cnt << std::endl;

    return 0;
}
