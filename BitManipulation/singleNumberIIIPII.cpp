#include <bits/stdc++.h>

int main() {

    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int xorr = 0;
    for (int i = 0; i < n; i++) {
        xorr ^= arr[i];
    }
    int rightMostBit = (xorr & (xorr - 1)) ^ xorr;
    int one = 0;
    int two = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] & rightMostBit)
            one ^= arr[i];
        else
            two ^= arr[i];
    }
    std::cout << one << ' ' << two << std::endl;

    return 0;
}
