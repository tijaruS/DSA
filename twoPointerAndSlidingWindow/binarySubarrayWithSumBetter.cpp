#include <bits/stdc++.h>

int main() {
    int n, sum;
    std::cin >> n >> sum;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int cnt = 0, l = 0, r = 0, ssum = 0;
    while (r < n) {
        ssum += arr[r];

        while (ssum != sum) {
            ssum -= arr[l];
            if (ssum == sum)
                cnt++;
            l++;
        }

        if (ssum == sum)
            cnt++;
        r++;
    }
    std::cout << cnt << std::endl;

    return 0;
}
