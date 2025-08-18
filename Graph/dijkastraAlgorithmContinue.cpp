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

    std::vector<int> dist(n, 1e9);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        pq;
    dist[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        int node = pq.top().second;
        int wt = pq.top().first;
        pq.pop();
        for (auto &it : adj[node]) {
            if (dist[node] + it.first < dist[it.second]) {
                dist[it.second] = dist[node] + it.first;
                pq.push({dist[it.second], it.second});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << dist[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
