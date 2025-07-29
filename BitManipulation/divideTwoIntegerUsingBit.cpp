#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
    int divident, divisor;
    std::cin >> divident >> divisor;
    if(divisor==0){
        std::cerr<<"Divide by zero error"<<std::endl;
        return 1;
    }
    long long ans = 0;
    bool sign = true;

    if ((divident >= 0 && divisor < 0) || (divident < 0 && divisor > 0))
        sign = false;
    long long n = std::abs((long long)divident);
    long long d = std::abs((long long)divisor);
    while (n >= d) {

        int cnt = 0;
        while (n >= (d << (cnt + 1))) {
            cnt++;
        }

        ans += 1 << cnt;
        n -= (d << (cnt));
    }
    ans = sign ? ans : -ans;
    if (ans > INT_MAX)
        ans = INT_MAX;
    if (ans < INT_MIN)
        ans = INT_MIN;

    std::cout << (int)ans << std::endl;
    return 0;
}
