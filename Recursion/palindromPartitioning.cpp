#include <bits/stdc++.h>
bool isPalindrom(std::string s, int i, int j) {
    while (i <= j) {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}
void partition(int startingInd, std::string &s,
               std::vector<std::vector<std::string>> &ans,
               std::vector<std::string> &ds) {
    if (startingInd == s.length()) {
        ans.push_back(ds);
        return;
    }
    for (int i = startingInd; i < s.length(); i++) {
        if (isPalindrom(s, startingInd, i)) {
            ds.push_back(s.substr(startingInd, i - startingInd + 1));
            partition(i + 1, s, ans, ds);
            ds.pop_back();
        }
    }
}

int main() {
    std::string s;
    std::cin >> s;
    std::vector<std::vector<std::string>> ans;
    std::vector<std::string> ds;
    partition(0, s, ans, ds);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            std::cout << ans[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
