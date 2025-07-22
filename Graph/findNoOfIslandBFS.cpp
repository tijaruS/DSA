#include <bits/stdc++.h>
void bfs(int row, int col, std::vector<std::vector<int>> &grid,
         std::vector<std::vector<int>> &vis) {
    int n = grid.size();
    int m = grid[0].size();

    std::queue<std::pair<int, int>> q;
    q.push({row, col});

    while (!q.empty()) {
        int rowq = q.front().first;
        int colq = q.front().second;
        q.pop();

        // if diagonal is not considerd the this will be used
        // int delRow[] = {-1,1,0,0}
        // int delCol[]={0,0,-1,1}
        // for(int i=0;i<4;i++){
        //
        // int nrow = rowq + delRow[i];
        // int ncol = colq + delCol[i];
        //
        // if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
        // !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
        // vis[nrow][ncol] = 1;
        // q.push({nrow, ncol});
        // }
        // }

        for (int delRow = -1; delRow <= 1; delRow++) {
            for (int delCol = -1; delCol <= 1; delCol++) {
                int nrow = rowq + delRow;
                int ncol = colq + delCol;
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> grid(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> grid[i][j];
        }
    }
    std::vector<std::vector<int>> vis(n, std::vector<int>(m));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && grid[i][j] == 1) {
                cnt++;
                bfs(i, j, grid, vis);
            }
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}
