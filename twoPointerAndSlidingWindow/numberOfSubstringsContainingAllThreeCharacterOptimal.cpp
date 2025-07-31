#include <bits/stdc++.h>
#include <chrono>

int main() {
    std::string s;
    std::cin >> s;

    auto start = std::chrono::high_resolution_clock::now();
    int n = s.length();
    int ans = 0;
    std::vector<int> hash(3, -1);
    for (int i = 0; i < n; i++) {
        hash[s[i] - 'a'] = i;
        if (hash[s[0]] != -1 && hash[s[1]] != -1 && hash[s[2]] != -1) {
            ans += (1 + std::min({hash[0], hash[1], hash[2]}));
        }
    }
    std::cout << ans << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Time taken: " << duration.count() << " ms" << std::endl;
    return 0;
}
