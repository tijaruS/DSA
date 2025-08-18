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
        for (auto i : adj[node]) {
            if (dist[node] + i.first < dist[i.second]) {
                dist[i.second] = dist[node] + i.first;
                s.insert({dist[i.second], i.second});
            }
        }
    }
    for (auto it : dist) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;

    return 0;
}
