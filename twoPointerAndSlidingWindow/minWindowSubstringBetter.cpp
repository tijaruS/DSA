#include <bits/stdc++.h>

int main() {
    std::string s, t;
    std::cin >> s >> t;

    int l = 0, r = 0, len = INT_MAX, slen = 0;
    std::map<char, int> m;
    for (char c : t)
        m[c]++;
    int cnt = 0;
    while (r < s.length()) {
        if (m[s[r]] > 0)
            cnt++;
        m[s[r]]--;

        while (cnt == t.length()) {
            if (r - l + 1 < len) {
                len = r - l + 1;
                slen = l;
            }
            m[s[l]]++;
            if (m[s[l]] > 0)
                cnt--;
            l++;
        }
        r++;
    }
    if (len == INT_MAX)
        std::cout << "No substring found" << std::endl;
    else
        std::cout << s.substr(slen, len) << std::endl;

    return 0;
}
