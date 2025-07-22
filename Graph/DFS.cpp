#include <bits/stdc++.h>

void DFS(int numNode, std::vector<int> adj[], int startingNode,
         std::vector<int> &ans, std::vector<int> &vis) {
    vis[startingNode] = 1;
    ans.push_back(startingNode);
    for (auto neighbor : adj[startingNode]) {
        if (!vis[neighbor])
            DFS(numNode, adj, neighbor, ans, vis);
    }
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
    std::vector<int> ans;
    std::vector<int> visited(n);

    DFS(n, adj, 0, ans, visited);

    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
