#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<string, string> pss;
bool isSafe(int row, int col, vector<string> board, int n) {
    int trow = row;
    int tcol = col;

    while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }
    row = trow;
    col = tcol;
    while (col >= 0) {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }
    row = trow;
    col = tcol;
    while (row < n && col >= 0) {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }
    return true;
}
void checkIfPossible(int col, vector<string> &board,
                     vector<vector<string>> &ans, int n) {
    if (col == n) {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            checkIfPossible(col + 1, board, ans, n);
            board[row][col] = '.';
        }
    }
}
void solve() {
    int n;
    cin >> n;
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++) {
        board[i] = s;
    }
    checkIfPossible(0, board, ans, n);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j];
            cout << endl;
        }
        cout << endl;
    }
}
int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
