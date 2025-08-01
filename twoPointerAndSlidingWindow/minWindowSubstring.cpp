#include <bits/stdc++.h>

int main() {
    std::string s, t;
    std::cin >> s >> t;
    int slen = 0;
    int len = INT_MAX;

    for (int i = 0; i < s.length(); i++) {
        std::map<char, int> m;

        int cnt = 0;
        for (int j = 0; j < t.length(); j++) {
            m[t[j]]++;
        }
        for (int k = i; k < s.length(); k++) {
            if (m[s[k]] > 0) {
                cnt++;
            }

            m[s[k]]--;
            if (cnt == t.length()) {
                if (k - i + 1 < len) {
                    len = k - i + 1;
                    slen = i;
                }
                break;
            }
        }
    }
    if (len == INT_MAX)
        std::cout << "No substring found" << std::endl;
    else
        std::cout << (s.substr(slen, len)) << std::endl;

    return 0;
}
