#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
    int first, second;
};

int maxChainLength(Pair arr[], int n) {
    sort(arr, arr + n, [](const Pair& x, const Pair& y) {
        if (x.first == y.first) return x.second < y.second;
        return x.first < y.first;
        });

    vector<int> dp(n, 1);  

    //dynamic programming here
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j].second < arr[i].first && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }


    return *max_element(dp.begin(), dp.end());
}

int main() {
    Pair arr1[] = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Chain max length :  " << maxChainLength(arr1, n1) << endl;

    Pair arr2[] = { {5, 10}, {1, 11} };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Chain max length : " << maxChainLength(arr2, n2) << endl;

    return 0;
}