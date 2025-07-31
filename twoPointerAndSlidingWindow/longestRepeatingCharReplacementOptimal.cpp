#include <bits/stdc++.h>

int main() {
    std::string s;
    int k;
    std::cin >> s >> k;
    int n = s.length();
    int maxL = 0, l = 0, r = 0, maxf = 0;
    std::vector<int> hash(26, 0);
    while (r < n) {
        hash[s[r] - 'A']++;
        maxf = std::max(maxf, hash[s[r] - 'A']);
        if (r - l + 1 - maxf > k) {
            hash[s[l] - 'A']--;
            l++;
        }
        if (r - l + 1 - maxf <= k) {
            maxL = std::max(maxL, r - l + 1);
        }
        r++;
    }
    std::cout << maxL << std::endl;

    return 0;
}
