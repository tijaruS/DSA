#include <bits/stdc++.h>

int main() {
    std::string s;
    std::cin >> s;
    int len = s.length();
    int l = 0, r = 0, maxsum = 0;
    std::vector<int> hash(255, -1);
    while (r < len) {
        if (hash[s[r]] != -1) {
            if (hash[s[r]] >= l) {
                l = hash[s[r]] + 1;
            }
        }
        maxsum = std::max(maxsum, r - l + 1);
        hash[s[r]] = r;
        r++;
    }
    std::cout << maxsum << std::endl;

    return 0;
}
