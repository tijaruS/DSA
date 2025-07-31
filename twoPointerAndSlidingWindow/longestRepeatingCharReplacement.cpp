#include <bits/stdc++.h>

int main() {
    std::string s;
    int k;
    std::cin >> s >> k;
    int n = s.length();
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        std::vector<int> hash(26, 0);
        int maxf = 0;
        int change = 0;
        for (int j = i; j < n; j++) {
            hash[s[j] - 'A']++;
            maxf = std::max(maxf, hash[s[j] - 'A']);
            change = j - i + 1 - maxf;
            if (change <= k)
                maxLen = std::max(maxLen, j - i + 1);
            else
                break;
        }
    }
    std::cout << maxLen << std::endl;

    return 0;
}
