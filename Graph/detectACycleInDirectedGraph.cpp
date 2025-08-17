#include <bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> adj[n];
    for (int i = 0; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
    }
    std::vector<int> indegree(n);

    for (int i = 0; i < n; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }
    std::vector<int> topo;
    std::queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    std::cout << (topo.size() == n ? "No Cycle" : "Cycle detected")
              << std::endl;

    return 0;
}
