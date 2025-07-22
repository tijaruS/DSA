#include <bits/stdc++.h>
// This is for 0 based indexing graph for one based indexing take adj list of
// size n+1
std::vector<int> BFS(int numNode, std::vector<int> adj[], int startingNode) {
    std::queue<int> q;
    std::vector<int> vis(numNode, 0);
    std::vector<int> ans;
    vis[startingNode] = 1;
    q.push(startingNode);

    while (!q.empty()) {
        int current_node = q.front();
        q.pop();
        ans.push_back(current_node);
        for (auto neighbor : adj[current_node]) {
            if (!vis[neighbor]) {
                vis[neighbor] = 1;

                q.push(neighbor);
            }
        }
    }
    return ans;
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
    std::vector<int> ans = BFS(n, adj, 0);

    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}
