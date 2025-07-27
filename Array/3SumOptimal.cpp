#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());
    std::vector<std::vector<int>> ans;
    for (int i = 0; i < n; i++) {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum > 0) {
                k--;
            } else if (sum < 0) {
                j++;
            } else {
                std::vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
    }
    for (int i = 0; i < ans.size(); i++) {

        for (int j = 0; j < ans[0].size(); j++) {
            std::cout << ans[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
