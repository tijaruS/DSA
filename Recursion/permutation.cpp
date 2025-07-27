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
void findPerm(vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans,
              int freq[]) {
    if (ds.size() == arr.size()) {
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < arr.size(); i++) {
        if (!freq[i]) {
            ds.push_back(arr[i]);
            freq[i] = 1;
            findPerm(arr, ds, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
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
    vector<int> ds;
    int freq[n];
    for (int i = 0; i < n; i++) {
        freq[i] = 0;
    }
    findPerm(arr, ds, ans, freq);
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
