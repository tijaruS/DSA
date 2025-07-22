#include <bits/stdc++.h>
bool detectCycleDirected(int startingNode, std::vector<int> adj[],
                         std::vector<int> &vis, std::vector<int> dfsvis) {
    vis[startingNode] = 1;
    dfsvis[startingNode] = 1;
    for (auto adjacent : adj[startingNode]) {
        if (!vis[adjacent]) {
            if (detectCycleDirected(adjacent, adj, vis, dfsvis) == true)
                return true;
        } else if (dfsvis[adjacent])
            return true;
    }
    dfsvis[startingNode] = 0;
    return false;
}
bool checkIfCycle(int noOfNodes, std::vector<int> adj[], std::vector<int> &vis,
                  std::vector<int> &dfsvis) {
    for (int i = 0; i < noOfNodes; i++) {
        if (!vis[i]) {
            if (detectCycleDirected(i, adj, vis, dfsvis) == true)
                return true;
        }
    }
    return false;
}
int main() {
    int nodes, edges;
    std::cin >> nodes >> edges;
    std::vector<int> adj[nodes];
    for (int i = 0; i < edges; i++) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
    }
    std::vector<int> vis(nodes);
    std::vector<int> dfsvis(nodes);
    bool isCycle = checkIfCycle(nodes, adj, vis, dfsvis);
    std::cout << (isCycle ? "Cycle Detected" : "Cycle Not Detected")
              << std::endl;
    return 0;
}
