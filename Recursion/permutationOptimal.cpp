#include <bits/stdc++.h>
void perm(int startingInd, std::vector<int> &arr,
          std::vector<std::vector<int>> &ans) {
    if (startingInd == arr.size()) {
        ans.push_back(arr);
        return;
    }

    for (int i = startingInd; i < arr.size(); i++) {
        std::swap(arr[startingInd], arr[i]);
        perm(startingInd + 1, arr, ans);
        std::swap(arr[startingInd], arr[i]);
    }
}
int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int &x : arr) {
        std::cin >> x;
    }
    std::vector<std::vector<int>> ans;
    perm(0, arr, ans);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            std::cout << ans[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
