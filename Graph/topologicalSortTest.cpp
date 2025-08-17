#include <bits/stdc++.h>

void dfs(int startingInd, std::stack<int> &st, std::vector<int> arr[],
         std::vector<int> &vis) {
    vis[startingInd] = 1;
    for (auto adj : arr[startingInd]) {
        if (!vis[adj]) {
            dfs(adj, st, arr, vis);
        }
    }
    st.push(startingInd);
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> arr[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    std::stack<int> st;

    std::vector<int> vis(n);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, st, arr, vis);
        }
    }
    while (!st.empty()) {
        std::cout << st.top() << std::endl;
    }

    return 0;
}
