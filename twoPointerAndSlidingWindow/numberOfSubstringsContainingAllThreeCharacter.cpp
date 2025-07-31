#include <bits/stdc++.h>

int main() {
    std::string s;
    std::cin >> s;
    int n = s.length();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        std::vector<int> hash(3);
        for (int j = i; j < n; j++) {
            hash[s[j]-'a']=1;
            if(hash[0]+hash[1]+hash[2]==3) {
                // ans++; 

                //optimization
                ans+=n-j;
                break;
            }
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
