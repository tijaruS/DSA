#include <bits/stdc++.h>
void subsets(int startingInd, int n, std::vector<int> &arr,
             std::set<std::vector<int>> &ans, std::vector<int> &ds) {
    if (startingInd == n) {
        ans.insert(ds);
        return;
    }
    ds.push_back(arr[startingInd]);
    subsets(startingInd + 1, n, arr, ans, ds);
    ds.pop_back();
    subsets(startingInd + 1, n, arr, ans, ds);
}
int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int &x : arr) {
        std::cin >> x;
    }
    std::sort(arr.begin(), arr.end());
    std::set<std::vector<int>> ans;
    std::vector<int> ds;
    subsets(0, n, arr, ans, ds);
    for (const auto &vec : ans) {
        for (int i : vec) {
            std::cout << i << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
