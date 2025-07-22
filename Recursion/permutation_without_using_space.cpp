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
void genPerm(int ind, vector<int> &arr, vector<vector<int>> &ans) {
  if (ind == arr.size()) {
    ans.push_back(arr);
    return;
  }
  for (int i = ind; i < arr.size(); i++) {
    swap(arr[ind], arr[i]);
    genPerm(ind + 1, arr, ans);
    swap(arr[ind], arr[i]);
  }
}
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<vector<int>> ans;
  genPerm(0, arr, ans);
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
}
int32_t main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
