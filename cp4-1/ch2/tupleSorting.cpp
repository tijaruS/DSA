#include <bits/stdc++.h>
#include <tuple>

int main() {
    std::vector<std::tuple<int, std::string, std::string>> test;
    int numOfTuple;
    std::cin >> numOfTuple;
    for (int i = 0; i < numOfTuple; i++) {
        int num;
        std::string str1;
        std::string str2;
        std::cin >> num >> str1 >> str2;
        test.push_back(std::make_tuple(num, str1, str2));
    }
    sort(test.begin(), test.end(), [](const auto &a, const auto &b) {
        if (std::get<0>(a) != std::get<0>(b))
            return std::get<0>(a) < std::get<0>(b);
        if (std::get<1>(a) != std::get<1>(b))
            return std::get<1>(a) > std::get<1>(b);
        if (std::get<2>(a) != std::get<2>(b))
            return std::get<2>(a) < std::get<2>(b);
    });
    for (const auto &i : test) {
        std::cout << std::get<0>(i) << ", " << std::get<1>(i) << ", "
                  << std::get<2>(i);
        std::cout << std::endl;
    }

    return 0;
}
