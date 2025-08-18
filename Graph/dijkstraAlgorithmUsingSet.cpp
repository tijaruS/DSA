#include <bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    std::set<std::pair<int, int>> s;
    std::vector<int> dist(n, 1e9);
    dist[0] = 0;
    s.insert({0, 0});
    while (!s.empty()) {
        auto it = *(s.begin());
        int node = it.second;
        int wt = it.first;
        s.erase(it);
        for (auto &a : adj[node]) {
            if (dist[node] + a.first < dist[a.second]) {
                dist[a.second] = dist[node] + a.first;
                s.insert({dist[a.second], a.second});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << dist[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}
