#include <bits/stdc++.h>
int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);

    for (int &i : arr) {
        std::cin >> i;
    }
    std::stack<int> st;
    std::vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] <= st.top()) {
            st.pop();
        }
        if (!st.empty())
            ans[i] = st.top();
        else
            ans[i] = -1;
        st.push(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
