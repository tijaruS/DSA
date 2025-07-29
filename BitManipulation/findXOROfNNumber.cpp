#include <bits/stdc++.h>
int find(int n) {
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    if (n % 4 == 3)
        return 0;
    return n;
}
int main() {
    int n;
    std::cin >> n;
    std::cout << find(n) << std::endl;
    // if we have to find in the interval l to r ==> find(l-1)^find(r);

    return 0;
}
