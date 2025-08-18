#include <bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v;

        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::queue<int> q;
    std::vector<int> dist(n, 1e9);
    dist[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto it : adj[node]) {
            if (dist[node] + 1 < dist[it]) {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    std::vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        if (dist[i] != 1e9)
            ans[i] = dist[i];
    }
    for (int it : ans)
        std::cout << it << ' ';
    std::cout << std::endl;

    return 0;
}
