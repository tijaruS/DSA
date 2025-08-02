#include <bits/stdc++.h>
void csum(int startingInd, std::vector<int> &arr,
          std::vector<std::vector<int>> &ans, int k, std::vector<int> &ds) {
    if (startingInd == arr.size()) {
        if (k == 0)
            ans.push_back(ds);
        return;
    }
    if (arr[startingInd] <= k) {
        ds.push_back(arr[startingInd]);
        csum(startingInd, arr, ans, k - arr[startingInd], ds);
        ds.pop_back();
    }
    csum(startingInd + 1, arr, ans, k, ds);
}
int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::vector<std::vector<int>> ans;
    std::vector<int> ds;
    csum(0, arr, ans, k, ds);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            std::cout << ans[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
