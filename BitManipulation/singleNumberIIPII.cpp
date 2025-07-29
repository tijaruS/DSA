#include <algorithm>
#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());

    int ans=arr[n-1];
    for (int i = 1; i < n; i += 3) {
        if (arr[i] != arr[i - 1]) {
            ans = arr[i - 1];
            break;
        }
    }
    
    std::cout << ans << std::endl;

    return 0;
}
