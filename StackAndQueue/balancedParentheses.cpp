#include <bits/stdc++.h>
int main() {
    std::string s;
    std::cin >> s;
    std::stack<int> st;
    bool flag = true;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (!st.empty()) {
                char c = st.top();
                if ((s[i] == ')' && c == '(') || (s[i] == '}' && c == '{') ||
                    (s[i] == ']' && c == '['))
                    st.pop();
                else {
                    flag = false;
                    break;
                }
            } else {
                flag = false;
                break;
            }
        }
    }
    if (!st.empty())
        flag = false;
    std::cout << (flag ? "valid" : "not valid") << std::endl;

    return 0;
}
