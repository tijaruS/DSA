#include <algorithm>
#include <bits/stdc++.h>
int getNoOfDays(std::vector<int> &arr, int cap) {
    int load = 0;
    int day = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (load + arr[i] > cap) {
            day++;
            load = arr[i];
        } else {
            load += arr[i];
        }
    }
    return day;
}

int main() {
    int size, day;
    std::cin >> size >> day;
    std::vector<int> arr(size);
    int sum = 0;
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
        sum += arr[i];
    }
    int low = *std::max_element(arr.begin(), arr.end());
    int high = sum;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (getNoOfDays(arr, mid) < day) {
            high = mid - 1;
        } else
            low = mid + 1;
    }
    std::cout << low << std::endl;

    return 0;
}
