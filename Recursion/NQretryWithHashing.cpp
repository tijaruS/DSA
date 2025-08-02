#include <bits/stdc++.h>
void check(int col, std::vector<std::string> &board,
           std::vector<std::vector<std::string>> &ans, int n,
           std::vector<int> &side, std::vector<int> &leftDia,
           std::vector<int> &rightDia) {
    if (col == n) {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (!side[row] && !leftDia[row + col] && !rightDia[n - 1 + col - row]) {
            board[row][col] = 'Q';
            side[row] = 1;
            leftDia[row + col] = 1;
            rightDia[n - 1 + col - row] = 1;
            check(col + 1, board, ans, n, side, leftDia, rightDia);
            board[row][col] = '.';
            side[row] = 0;
            leftDia[row + col] = 0;
            rightDia[n - 1 + col - row] = 0;
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
    std::vector<int> side(n, 0), leftDia(2 * n - 1, 0), rightDia(2 * n - 1, 0);
    check(0, board, ans, n, side, leftDia, rightDia);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            std::cout << ans[i][j] << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
