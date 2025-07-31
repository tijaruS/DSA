#include <bits/stdc++.h>

int main() {
    std::string s;
    int k;
    std::cin >> s >> k;
    int n = s.length();
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        std::set<char> st;
        for (int j = i; j < n; j++) {
            st.insert(s[j]);
            if (st.size() > k)
                break;
            if (st.size() <= k) {
                maxLen = std::max(maxLen, j - i + 1);
            }
        }
    }
    std::cout << maxLen << std::endl;

    return 0;
}
