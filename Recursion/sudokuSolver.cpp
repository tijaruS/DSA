#include <bits/stdc++.h>
bool ifPossible(int row, int col, int c,
                std::vector<std::vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == c)
            return false;
        if (board[i][col] == c)
            return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}
bool solve(std::vector<std::vector<char>> &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == '.') {
                for (int c = '1'; c <= '9'; c++) {
                    if (ifPossible(i, j, c, board)) {
                        board[i][j] = c;
                        if (solve(board) == true) {
                            return true;

                        } else
                            board[i][j] = '.';
                    }
                }

                return false;
            }
        }
    }
    return true;
}
int main() {

    std::vector<std::vector<char>> board(9, std::vector<char>(9, '.'));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cin >> board[i][j];
        }
    }
    solve(board);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
