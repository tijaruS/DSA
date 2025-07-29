#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    int subsets = 1 << n;
    std::vector<std::vector<int>> ans;

    for (int num = 0; num <= subsets - 1; num++) {
        std::vector<int> list;
        for (int i = 0; i < n; i++) {
            if (num & (1 << i))
                list.push_back(nums[i]);
        }
        ans.push_back(list);
    }

    for (int i = 0; i < ans.size(); i++) {
        std::cout << '[';
        for (int j = 0; j < ans[i].size(); j++) {
            if (j != ans[i].size() - 1)
                std::cout << ans[i][j] << ' ';
            else
                std::cout << ans[i][j];
        }
        std::cout << ']';
        std::cout << std::endl;
    }
    //INFO: TC - O(n*2^n) 
    //INFO: SC- O(2^n * n)

    return 0;
}
