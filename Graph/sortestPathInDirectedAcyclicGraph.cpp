#include <bits/stdc++.h>
#include <climits>
void dfs(int node, std::vector<std::pair<int, int>> adj[],
         std::vector<int> &vis, std::stack<int> &st) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it.first])
            dfs(it.first, adj, vis, st);
    }
    st.push(node);
}
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> adj[n];
    for (int i = 0; i < n; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    std::vector<int> dist(n);
    std::stack<int> st;
    std::vector<int> vis(n);
    for (int i = 0; i < n; i++) {
        if (!vis[i])
            dfs(i, adj, vis, st);
    }
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        for (auto it : adj[node]) {
            int wt = it.second;
            int n = it.first;
            if (dist[node] + wt > dist[n])
                dist[n] = dist[node] + wt;
        }
    }
    for (int i = 0; i < dist.size(); i++) {
        std::cout << dist[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
