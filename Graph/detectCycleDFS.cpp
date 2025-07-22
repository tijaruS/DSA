#include <bits/stdc++.h>

bool checkIfCycle(int startingNode, int parent, std::vector<int> adj[],
                  std::vector<int> &vis) {
    vis[startingNode] = 1;

    for (auto adjacent : adj[startingNode]) {
        if (!vis[adjacent]) {
            if (checkIfCycle(adjacent, startingNode, adj, vis) == true)
                return true;
        } else if (parent != adjacent)
            return true;
    }
    return false;
}
bool detectCycle(int noOfNode, int startingNode, std::vector<int> adj[],
                 std::vector<int> &vis) {
    for (int i = 0; i < noOfNode; i++) {
        if (!vis[i]) {
            if (checkIfCycle(i, -1, adj, vis) == true)
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
    bool ifHaveCycle = detectCycle(n, 0, adj, vis);
    std::cout << (ifHaveCycle ? "cycleDetected" : "No cycle") << std::endl;
    return 0;
}
