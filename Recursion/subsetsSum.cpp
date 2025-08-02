#include <bits/stdc++.h>
void subsets(int startingInd, int n, std::vector<int> &arr,
             std::vector<int> &ans, int &sum) {
    if (startingInd == n) {
        ans.push_back(sum);
        return;
    }
    sum += arr[startingInd];
    subsets(startingInd + 1, n, arr, ans, sum);
    sum -= arr[startingInd];
    subsets(startingInd + 1, n, arr, ans, sum);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int &x : arr) {
        std::cin >> x;
    }
    std::vector<int> ans;
    int sum = 0;
    subsets(0, n, arr, ans, sum);
    std::sort(ans.begin(), ans.end());
    for (int a : ans) {
        std::cout << a << ' ';
    }
    std::cout << std::endl;

    return 0;
}
