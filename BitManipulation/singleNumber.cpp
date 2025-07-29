#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[arr[i]]++;
    }
    int ans;
    for (auto it : m) {
        if (it.second == 1)
            ans = it.first;
    }
    std::cout << "The single element is: " << ans << std::endl;
    // we can take xor of all the element to find the single element too as
    // a^a=0 and 0 ^ a=a;
    int ans2 = 0;
    for (int i = 0; i < n; i++) {
        ans2 ^= arr[i];
    }
    std::cout << "The single element using xor is: " << ans2 << std::endl;
    return 0;
}
