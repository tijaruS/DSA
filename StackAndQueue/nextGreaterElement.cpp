#include <bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> num1(n), num2(m);
    for (int i = 0; i < n; i++) {
        std::cin >> num1[i];
    }
    for (int &x : num2) {
        std::cin >> x;
    }
    std::vector<int> ans(m);
    std::vector<int> ans2(n);
    std::map<int, int> mp;
    std::stack<int> st;
    for (int i = m - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= num2[i]) {
            st.pop();
        }
        if (!st.empty()) {
            mp[num2[i]] = st.top();
            ans[i] = st.top();
        } else {
            mp[num2[i]] = -1;
            ans[i] = -1;
        }
        st.push(num2[i]);
    }
    for (int i : ans) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << mp[num1[i]] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
