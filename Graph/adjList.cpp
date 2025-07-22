#include <bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> adj[n + 1];

    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        // for directed graph just push one
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}
