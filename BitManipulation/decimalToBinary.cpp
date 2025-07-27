#include <bits/stdc++.h>

int main() {
    int number;
    std::cin >> number;
    std::string s = "";
    while (number > 0) {
        if (number % 2 == 1)
            s += '1';
        else
            s += '0';
        number /= 2;
    }
    // using c++ inbuild binaryrepresentataion funcion
    // 
    std::reverse(s.begin(), s.end());
    std::cout << s << std::endl;
}
