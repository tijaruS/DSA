#include <bits/stdc++.h>
int findcnt(std::vector<int> &arr, int goal) {
    if (goal < 0)
        return 0;
    int cnt = 0, l = 0, r = 0, sum = 0;
    int n = arr.size();
    while (r < n) {
        sum += arr[r];
        while (sum > goal) {
            sum -= arr[l];
            l++;
        }
        cnt += r - l + 1;
        r++;
    }
    return cnt;
}
int main() {
    int n, goal;
    std::cin >> n >> goal;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::cout << (findcnt(arr, goal) - findcnt(arr, goal - 1)) << std::endl;

    return 0;
}
