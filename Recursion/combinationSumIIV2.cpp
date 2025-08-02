#include <bits/stdc++.h>
void csum(int startingInd, int n, int k, std::vector<int> &arr,
          std::vector<std::vector<int>> &ans, std::vector<int> &ds) {
    if (k == 0) {
        ans.push_back(ds);
        return;
    }
    for (int i = startingInd; i < n; i++) {
        if (arr[i] > k)
            break;
        if (i > startingInd && arr[i] == arr[i - 1])
            continue;
        ds.push_back(arr[i]);
        csum(i + 1, n, k - arr[i], arr, ans, ds);
        ds.pop_back();
    }
}
int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int &x : arr) {
        std::cin >> x;
    }
    std::vector<std::vector<int>> ans;
    std::vector<int> ds;
    std::sort(arr.begin(), arr.end());
    csum(0, n, k, arr, ans, ds);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            std::cout << ans[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
