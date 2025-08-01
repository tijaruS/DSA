#include <bits/stdc++.h>
int findpivot(std::vector<int> &arr, int low, int high) {
    int i = low;
    int j = high;
    int pivot = low;
    while (i <= j) {
        // keeps on going till it does not find the element greater than pivot
        // element
        while (i <= high && arr[i] <= arr[pivot]) {
            i++;
        }
        // keeps on goinig till it does find the element smaller than pivot
        while (j >= low && arr[j] > arr[pivot]) {
            j--;
        }
        if (i < j)
            std::swap(arr[i], arr[j]);
    }
    std::swap(arr[low], arr[j]);
    return j;
}
void quicksort(std::vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivot = findpivot(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}
int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int low = 0;
    int high = n - 1;
    quicksort(arr, low, high);
    for (auto it : arr) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;

    return 0;
}
