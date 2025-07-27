#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;

    int reverseNumber = 0;
    while (n > 0) {
        int lastDigit = n % 10;
        n = n / 10;
        reverseNumber = (reverseNumber * 10) + lastDigit;
    }
    std::cout << reverseNumber << std::endl;
    return 0;
}
