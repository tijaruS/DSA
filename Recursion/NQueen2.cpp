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
void checkIfPossible(int col, vector<string> &board,
                     vector<vector<string>> &ans, int n, vector<int> &leftRow,
                     vector<int> &upperDiagonal, vector<int> &lowerDiagonal) {
  if (col == n) {
    ans.push_back(board);
    return;
  }

  for (int row = 0; row < n; row++) {
    if (leftRow[row] == 0 && upperDiagonal[row + col] == 0 &&
        lowerDiagonal[n - 1 + col - row] == 0) {
      board[row][col] = 'Q';
      leftRow[row] = 1;
      upperDiagonal[row + col] = 1;
      lowerDiagonal[n - 1 + col - row] = 1;
      checkIfPossible(col + 1, board, ans, n, leftRow, upperDiagonal,
                      lowerDiagonal);
      board[row][col] = '.';
      leftRow[row] = 0;
      upperDiagonal[row + col] = 0;
      lowerDiagonal[n - 1 + col - row] = 0;
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
  vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0),
      lowerDiagonal(2 * n - 1, 0);
  checkIfPossible(0, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);
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
