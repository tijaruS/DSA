#include <bits/stdc++.h>
void subsets(int startingInd, int n, std::vector<int> &arr,
             std::vector<std::vector<int>> &ans, std::vector<int> &ds) {
    ans.push_back(ds);
    for (int i = startingInd; i < n; i++) {
        if (i > startingInd && arr[i] == arr[i - 1])
            continue;
        ds.push_back(arr[i]);
        subsets(i + 1, n, arr, ans, ds);
        ds.pop_back();
    }
}
int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int &x : arr) {
        std::cin >> x;
    }
    sort(arr.begin(), arr.end());
    std::vector<std::vector<int>> ans;
    std::vector<int> ds;
    subsets(0, n, arr, ans, ds);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            std::cout << ans[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << '\n';

    return 0;
}
