#include <bits/stdc++.h>

int main() {
    std::string s;
    std::cin >> s;
    int n = s.length();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        std::set<char> st;
        for (int j = i; j < n; j++) {
            st.insert(s[j]);
            if (st.size() == 3)
                ans++;
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
