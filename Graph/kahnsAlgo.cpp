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
        for (int a : adj[i]) {
            indegree[a]++;
        }
    }
    std::queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
    std::vector<int> topo;
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
    for (auto it : topo)
        std::cout << it << ' ';
    std::cout << std::endl;

    return 0;
}
