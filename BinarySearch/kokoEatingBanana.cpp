#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>

long long countHr(std::vector<int> &arr, int bananaPerHour) {
    long long totalHour = 0;
    for (int i = 0; i < arr.size(); i++) {
        // another ways to write this is
        //  totalHour+= (arr[i]+bananaPerHour-1)/bananaPerHour;
        totalHour += std::ceil((double)arr[i] / (double)bananaPerHour);
    }
    return totalHour;
}
int main() {
    int n, h;
    std::cin >> n >> h;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int low = 1;
    int high = *std::max_element(arr.begin(), arr.end());
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long totalHour = countHr(arr, mid);
        if (totalHour <= h) {
            high = mid - 1;
        } else
            low = mid + 1;
    }
    std::cout << low << std::endl;
    return 0;
}
