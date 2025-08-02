#include <algorithm>
#include <bits/stdc++.h>
void csum(int startingInd, std::vector<int> &arr,
          std::set<std::vector<int>> &ans, std::vector<int> &ds, int k, int n) {
    if (startingInd == n) {
        if (k == 0)
            ans.insert(ds);
        return;
    }
    if (arr[startingInd] <= k) {
        ds.push_back(arr[startingInd]);
        csum(startingInd + 1, arr, ans, ds, k - arr[startingInd], n);
        ds.pop_back();
    }
    csum(startingInd + 1, arr, ans, ds, k, n);
}
int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());
    std::set<std::vector<int>> ans;
    std::vector<int> ds;
    csum(0, arr, ans, ds, k, n);
    for (const auto &vec : ans) {
        for (int num : vec) {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
