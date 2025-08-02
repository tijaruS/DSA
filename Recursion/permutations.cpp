#include <bits/stdc++.h>
void findperm(std::vector<int> &arr, std::vector<std::vector<int>> &ans,
              std::vector<int> &vis, std::vector<int> &ds) {
    if (ds.size() == arr.size()) {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < arr.size(); i++) {
        if (!vis[i]) {
            vis[i] = 1;
            ds.push_back(arr[i]);
            findperm(arr, ans, vis, ds);
            vis[i] = 0;
            ds.pop_back();
        }
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
    std::vector<int> vis(n);
    std::vector<int> ds;
    findperm(arr, ans, vis, ds);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            std::cout << ans[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
