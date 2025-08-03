#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int &i : arr) {
        std::cin >> i;
    }
    int l = 0;
    int r = n - 1;
    int lmax = 0;
    int rmax = 0;
    int cnt = 0;
    while (l < r) {
        if (arr[l] <= arr[r]) {
            if (lmax > arr[l]) {
                cnt += lmax - arr[l];
            } else
                lmax = arr[l];
            l++;
        } else {
            if (rmax > arr[r]) {
                cnt += rmax - arr[r];
            } else
                rmax = arr[r];
            r--;
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}
