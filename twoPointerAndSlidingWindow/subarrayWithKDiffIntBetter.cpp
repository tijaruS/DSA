#include <bits/stdc++.h>
int findans(std::vector<int> &arr, int k) {
    if (k < 0)
        return 0;
    int n = arr.size();
    std::map<int, int> m;
    int cnt = 0, l = 0, r = 0;
    while (r < n) {
        m[arr[r]]++;
        while (m.size() > k) {
            m[arr[l]]--;
            if (m[arr[l]] == 0)
                m.erase(arr[l]);
            l++;
        }
        cnt += r - l + 1;

        r++;
    }
    return cnt;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::cout << findans(arr,k)-findans(arr, k-1)<< std::endl;

    return 0;
}
