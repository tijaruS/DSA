#include <bits/stdc++.h>

int main() {
    std::string s;
    std::cin >> s;

    int maxLength = 0;
    for (int i = 0; i < s.length(); i++) {

        std::vector<int> hash(255, 0);
        for (int j = i; j < s.length(); j++) {
            if (hash[s[j]])
                break;
            maxLength = std::max(maxLength, j - i + 1);
            hash[s[j]]++;
        }
    }
    std::cout << maxLength << std::endl;

    return 0;
}
