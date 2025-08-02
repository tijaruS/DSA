#include <bits/stdc++.h>
bool safe(int row, int col, std::vector<std::string> &board, int n) {
    int trow = row;
    int tcol = col;
    while (row >= 0 && col >= 0) {
        if (board[row--][col--] == 'Q')
            return false;
    }
    row = trow;
    col = tcol;
    while (col >= 0) {
        if (board[row][col--] == 'Q')
            return false;
    }
    row = trow;
    col = tcol;
    while (row < n && col >= 0) {
        if (board[row++][col--] == 'Q')
            return false;
    }
    return true;
}
void check(int col, int n, std::vector<std::string> &board,
           std::vector<std::vector<std::string>> &ans) {
    if (col == n) {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (safe(row, col, board, n)) {
            board[row][col] = 'Q';
            check(col + 1, n, board, ans);
            board[row][col] = '.';
        }
    }
}
int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> board(n);
    std::string s(n, '.');
    for (int i = 0; i < n; i++) {
        board[i] = s;
    }
    std::vector<std::vector<std::string>> ans;
    check(0, n, board, ans);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            std::cout << ans[i][j] << std::endl;
            ;
        }
        std::cout << std::endl;
    }

    return 0;
}
