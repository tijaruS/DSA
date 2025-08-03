#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int &x : arr) {
        std::cin >> x;
    }
    std::stack<int> st;
    std::vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[i] >= st.top()) {
            st.pop();
        }
        st.push(arr[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[i] >= st.top()) {
            st.pop();
        }
        if (!st.empty())
            ans.push_back(st.top());
        else
            ans.push_back(-1);
        st.push(arr[i]);
    }
    std::reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
