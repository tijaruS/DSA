#include <bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n >> m;

    // Use vector of vectors instead of VLA
    std::vector<std::vector<std::pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        // Store as {weight, destination}
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    // Min-heap: {distance, node}
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        pq;

    std::vector<int> dist(n, 1e9);
    dist[0] = 0;
    pq.push({0, 0}); // {distance, node}

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Skip if we've already found a better path to this node
        if (current_dist > dist[node]) {
            continue;
        }

        for (auto &edge : adj[node]) {
            int weight = edge.first;    // weight
            int neighbor = edge.second; // destination

            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << dist[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
