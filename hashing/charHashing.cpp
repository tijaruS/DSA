#include <bits/stdc++.h>

int main() {
    std::string s;
    std::cin >> s;
    std::vector<int> hash(26);
    for (int i = 0; i < s.length(); i++) {
        hash[s[i] - 'a']++;
    }
    int q;
    std::cin >> q;
    while (q--) {
        char c;
        std::cin >> c;
        std::cout << hash[c - 'a'] << std::endl;
    }

    return 0;
}
