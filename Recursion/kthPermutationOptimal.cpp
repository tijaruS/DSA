#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> factv;
    int fact = 1;
    for (int i = 1; i < n; i++) {
        fact *= i;
        factv.push_back(i);
    }
    factv.push_back(n);
    k = k - 1;
    std::string s = "";

    while (1) {
        s += std::to_string(factv[k / fact]);
        factv.erase(std::find(factv.begin(), factv.end(), factv[k / fact]));
        if (factv.size() == 0)
            break;
        k = k % fact;
        fact = fact / factv.size();
    }
    std::cout << s << std::endl;

    return 0;
}
