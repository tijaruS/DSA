#include <algorithm>
#include <bits/stdc++.h>
int checkIfPossibleToFormBouquets(std::vector<int> &arr, int day,
                                  int noOfBouquets, int consequitiveFlower) {
    int possibleBouquets = 0;
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (day >= arr[i])
            cnt++;
        else {
            possibleBouquets += cnt / consequitiveFlower;
            cnt = 0;
        }
    }
    possibleBouquets += cnt / consequitiveFlower;
    return possibleBouquets;
    // if (possibleBouquets >= noOfBouquets)
    // return true;
    // else
    // return false;
}
int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int low = *std::min_element(arr.begin(), arr.end());
    int high = *std::max_element(arr.begin(), arr.end());
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (checkIfPossibleToFormBouquets(arr, mid, m, k) < m) {
            low = mid + 1;
        } else
            high = mid - 1;
    }
    long long mul = (long long)m * (long long)k;
    if (mul > arr.size())
        std::cout << -1 << std::endl;
    else
        std::cout << low << std::endl;
    return 0;
}
