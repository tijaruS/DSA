#include <bits/stdc++.h>
int findcnt(std::vector<int> &arr, int goal) {
    if(goal<0) return 0;
    int n = arr.size();
    int sum = 0, l = 0, r = 0, cnt = 0;
    while (r < n) {
        sum += arr[r] % 2;
        while (sum > goal) {
            sum -= arr[l] % 2;
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

    std::cout << findcnt(arr, goal) - findcnt(arr, goal - 1) << std::endl;

    return 0;
}
