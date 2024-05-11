#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
    int first, second;
};
int maximumChainLength(Pair arr[], int n) {
    sort(arr, arr + n, [](const Pair& x, const Pair& y) {
        return x.second < y.second;
        });

    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j].second < arr[i].first) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}
int main() {
    Pair array1[] = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    int n_first = sizeof(array1) / sizeof(array1[0]);
    cout << "Maximum length of chain is " << maximumChainLength(array1, n_first) << endl;

    Pair array2[] = { {5, 10}, {1, 11} };
    int n_second = sizeof(array2) / sizeof(array2[0]);
    cout << "Maximum length of chain is " << maximumChainLength(array2, n_second) << endl;

    return 0;
}