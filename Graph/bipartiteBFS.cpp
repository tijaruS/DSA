#include <bits/stdc++.h>

bool check(int startingNode, int nodes, std::vector<int> adj[],
           std::vector<int> &color) {
    std::queue<int> q;
    q.push(startingNode);

    color[startingNode] = 0;
    while (!q.empty()) {
        int qnode = q.front();
        q.pop();

        for (auto adjacent : adj[qnode]) {
            if (color[adjacent] == -1) {
                color[adjacent] = !color[qnode];
                q.push(adjacent);
            } else if (color[adjacent] == color[qnode])
                return false;
        }
    }
    return true;
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
    std::vector<int> color(n, -1);
    bool ans = true;
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (check(i, n, adj, color) == false) {
                ans = false;
                break;
            }
        }
    }
    std::cout << (ans ? "biparted" : "not biparted") << std::endl;
    return 0;
}
