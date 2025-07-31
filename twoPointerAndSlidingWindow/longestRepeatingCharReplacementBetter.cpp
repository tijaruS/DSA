#include <bits/stdc++.h>

int main() {
    std::string s;
    int k;
    std::cin >> s >> k;
    int n = s.length();

    int maxLen = 0, l = 0, r = 0, maxF = 0;
    std::vector<int> hash(26, 0);

    while (r < n) {
        hash[s[r] - 'A']++;
        maxF = std::max(maxF, hash[s[r] - 'A']);
        while (r - l + 1 - maxF > k) {
            hash[s[l] - 'A']--;
            maxF = 0;
            for (int i = 0; i < 26; i++) {
                maxF = std::max(maxF, hash[i]);
            }
            l++;
        }
        if (r - l + 1 - maxF <= k)
            maxLen = std::max(maxLen, r - l + 1);
        r++;
    }
    std::cout << maxLen << std::endl;

    return 0;
}
