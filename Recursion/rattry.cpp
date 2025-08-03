#include <bits/stdc++.h>
void solve(int row, int col, int n, int m, std::vector<std::vector<int>> &arr,
           std::vector<std::string> &ans, std::vector<std::vector<int>> &vis,
           std::string s) {
    if (row == n - 1 && col == m - 1) {
        ans.push_back(s);
        return;
    }
    // downward
    if (row + 1 < n && !vis[row + 1][col] && arr[row + 1][col] == 1) {
        vis[row][col] = 1;
        solve(row + 1, col, n, m, arr, ans, vis, s + 'D');
        vis[row][col] = 0;
    }

    // leftward
    if (col - 1 >= 0 && !vis[row][col - 1] && arr[row][col - 1] == 1) {
        vis[row][col] = 1;
        solve(row, col - 1, n, m, arr, ans, vis, s + 'L');
        vis[row][col] = 0;
    }
    // rightward
    if (col + 1 < n && !vis[row][col + 1] && arr[row][col + 1] == 1) {
        vis[row][col] = 1;
        solve(row, col + 1, n, m, arr, ans, vis, s + 'R');
        vis[row][col] = 0;
    }
    // upward
    if (row - 1 >= 0 && !vis[row - 1][col] && arr[row - 1][col] == 1) {
        vis[row][col] = 1;
        solve(0, 0, n, m, arr, ans, vis, s + 'U');
        vis[row][col] = 0;
    }
}
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> arr(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> arr[i][j];
        }
    }
    std::vector<std::string> ans;
    std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));

    if (arr[0][0] == 1)
        solve(0, 0, n, m, arr, ans, vis, "");

    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << std::endl;
    }

    return 0;
}
