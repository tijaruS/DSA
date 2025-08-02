#include <bits/stdc++.h>
bool check(std::vector<std::vector<char>> &board,int row,int col,char c){
    for(int i=0;i<9;i++){
        if(board[row][i]==c) return false;
        if(board[i][col]==c) return false;
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;
    }
    return true;
}
bool isValid(std::vector<std::vector<char>> &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] != '.') {
                char c = board[i][j];
                board[i][j] = '.';
                if (!check(board, i, j, c))
                    return false;
                board[i][j] = c;
            }
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<char>> board(9, std::vector<char>(9, '.'));
    for (int i = 0; i < board.size(); i++) {

        for (int j = 0; j < board[0].size(); j++) {
            std::cin >> board[i][j];
        }
    }
    bool ans = isValid(board);
    std::cout << (ans ? "valid" : "not valid") << std::endl;

    return 0;
}
