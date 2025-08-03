#include <bits/stdc++.h>
void solve(int row, int col, int n, int m, std::vector<std::string> &ans,
           std::string s, std::vector<std::vector<int>> &arr,
           std::vector<std::vector<int>> &vis) {
    if (row == n - 1 && col == m - 1) {
        ans.push_back(s);
        return;
    }
    // move downward

    if (row + 1 < n && !vis[row + 1][col] && arr[row + 1][col] == 1) {
        vis[row][col] = 1;
        solve(row + 1, col, n, m, ans, s + 'D', arr, vis);
        vis[row][col] = 0;
    }

    // move leftward
    if (col - 1 >= 0 && !vis[row][col - 1] && arr[row][col - 1] == 1) {
        vis[row][col] = 1;
        solve(row, col - 1, n, m, ans, s + 'L', arr, vis);
        vis[row][col] = 0;
    }

    // move rightward
    if (col + 1 < n && !vis[row][col + 1] && arr[row][col + 1] == 1) {
        vis[row][col] = 1;
        solve(row, col + 1, n, m, ans, s + 'R', arr, vis);
        vis[row][col] = 0;
    }

    // move upward
    if (row - 1 >= 0 && !vis[row - 1][col] && arr[row - 1][col] == 1) {
        vis[row][col] = 1;
        solve(row - 1, col, n, m, ans, s + 'U', arr, vis);
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
        solve(0, 0, n, m, ans, "", arr, vis);

    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << std::endl;
    }

    return 0;
}
