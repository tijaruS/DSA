#include <bits/stdc++.h>
int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::string> arr(n);
    // std::vector<std::vector<char>> adj(n,std::vector<char>(k));
    std::vector<int> adj[k];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++) {
        std::string s1 = arr[i];
        std::string s2 = arr[i + 1];
        int j = 0;
        for (j = 0; j < std::min(s1.length(), s2.length()); j++) {
            if (s1[j] != s2[j]) {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                break;
            }
        }
    }
    std::vector<int> inorder(k);
    for (int i = 0; i < k; i++) {
        for (auto it : adj[i]) {
            inorder[it]++;
        }
    }
    std::queue<int> q;
    std::vector<int> topo;
    for (int i = 0; i < k; i++) {
        if (inorder[i] == 0)
            q.push(i);
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node]) {
            inorder[it]--;
            if (inorder[it] == 0)
                q.push(it);
        }
    }
    std::string ans = "";
    for (int i = 0; i < topo.size(); i++) {
        ans += static_cast<char>(topo[i] + 'a');
    }
    std::cout << ans << std::endl;

    return 0;
}
