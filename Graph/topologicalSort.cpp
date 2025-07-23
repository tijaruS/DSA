#include <bits/stdc++.h>
void dfs(int startingNode, std::stack<int> &st, std::vector<int> &vis,
         std::vector<int> adj[]) {
    vis[startingNode] = 1;
    for (auto adjacent : adj[startingNode]) {
        if (!vis[adjacent]) {
            dfs(adjacent, st, vis, adj);
        }
    }
    st.push(startingNode);
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
    }
    std::stack<int> st;
    std::vector<int> vis(n, 0);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, st, vis, adj);
        }
    }
    std::vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    for (auto it : ans) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;

    return 0;
}
