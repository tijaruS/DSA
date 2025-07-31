#include <bits/stdc++.h>
int main() {
    std::string s;
    int k;
    std::cin >> s >> k;
    int n = s.length();
    int maxLen = 0, l = 0, r = 0;
    std::map<char, int> m;
    while (r < n) {
        m[s[r]]++;
        if (m.size() > k) {
            m[s[l]]--;
            if (m[s[l]] == 0)
                m.erase(s[l]);
            l++;
        }
        if (m.size() <= k)
            maxLen = std::max(maxLen, r - l + 1);
        r++;
    }
    std::cout << maxLen << std::endl;

    return 0;
}
