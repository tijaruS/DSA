#include <bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj.push_back({u, v, w});
    }
    std::vector<int> dist(n, 1e9);
    dist[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto it : adj) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if (dist[u] != 1e9 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    bool isNegativeCycle = false;

    for (auto it : adj) {
        int u = it[0];
        int v = it[1];
        int w = it[2];
        if (dist[u] != 1e9 && dist[u] + w < dist[v])
            isNegativeCycle = true;
    }
    for (auto it : dist) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;
    std::cout << (isNegativeCycle ? "Negative Cycle detected"
                                  : "No negative cycle")
              << std::endl;

    return 0;
}
