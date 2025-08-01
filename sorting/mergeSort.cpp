#include <bits/stdc++.h>
void merge(std::vector<int> &arr, int left, int mid, int right) {
    std::vector<int> temp;
    int l = left;
    int r = mid + 1;
    while (l <= mid && r <= right) {
        if (arr[l] <= arr[r]) {
            temp.push_back(arr[l]);
            l++;
        } else {
            temp.push_back(arr[r]);
            r++;
        }
    }
    while (l <= mid) {
        temp.push_back(arr[l]);
        l++;
    }
    while (r <= right) {
        temp.push_back(arr[r]);
        r++;
    }
    for (int i = 0; i < temp.size(); i++) {
        arr[left + i] = temp[i];
    }
}
void mergesort(std::vector<int> &arr, int left, int right) {
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergesort(arr, left, mid);
    mergesort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int l = 0, r = n - 1;
    mergesort(arr, l, r);
    for (auto it : arr) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;

    return 0;
}
