#include <bits/stdc++.h>

int main() {
    std::string binary;
    std::cin >> binary;

    int decimal = 0;

    int len = binary.length();
    int p2 = 1;
    for (int i = len - 1; i >= 0; i--) {
        if (binary[i] == '1')
            decimal += p2;
        p2 *= 2;
    }
    std::cout << decimal << std::endl;
    return 0;
}
