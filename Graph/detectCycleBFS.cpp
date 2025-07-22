#include <bits/stdc++.h>

bool detectCycleBFS(int startingNode, std::vector<int> adj[],
                    std::vector<int> &vis) {
    std::queue<std::pair<int, int>> q;
    vis[startingNode] = 1;
    q.push({startingNode, -1});

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto adjacent : adj[node]) {
            if (!vis[adjacent]) {
                vis[adjacent] = 1;
                q.push({adjacent, node});

            } else if (parent != adjacent)
                return true;
        }
    }
    return false;
}
bool check(std::vector<int> adj[], std::vector<int> &vis, int noOfNode) {

    for (int i = 0; i < noOfNode; i++) {
        if (!vis[i]) {
            if (detectCycleBFS(i, adj, vis) == true)
                return true;
        }
    }
    return false;
}

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
    std::vector<int> vis(n, 0);
    bool ifHaveCycle = check(adj, vis, n);
    std::cout << (ifHaveCycle ? "cycleDetected" : "No cycle") << std::endl;
    return 0;
}
