#include <bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj(n, std::vector<int>(1e9));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u][v] = w;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adj[i][j] = std::min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1e9)
                adj[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << adj[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
