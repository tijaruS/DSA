#include <bits/stdc++.h>

int main() {
    int a, b;

    std::cin >> a >> b;

    while (a > 0 && b > 0) {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }

    if (a)
        std::cout << a << std::endl;
    else
        std::cout << b << std::endl;

    //INFO: TC-O(log(phi)(min(a,b)))
    return 0;
}
