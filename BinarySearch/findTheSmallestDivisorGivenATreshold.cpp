#include <algorithm>
#include <bits/stdc++.h>

int check(std::vector<int> &arr, int mid) {

    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += (arr[i] + mid - 1) / mid;
    }
    return sum;
}

int main() {
    int n, threshold;
    std::cin >> n >> threshold;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int low = 1;
    int high = *std::max_element(arr.begin(), arr.end());
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(arr, mid) > threshold) {

            low = mid + 1;

        } else
            high = mid - 1;
    }
    std::cout << low << std::endl;

    return 0;
}
