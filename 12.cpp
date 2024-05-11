#include <iostream>
#include <vector>
using namespace std;

int numberSequence(int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        dp[i][1] = 1;
    }
    
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= j / 2; k++) {
                dp[j][i] += dp[k][i - 1];
            }
        }
    }
    
    int total = 0;
    for (int i = 1; i <= m; i++) {
        total += dp[i][n];
    }
    
    return total;
}

int main() {
    int m1 = 10, n1 = 4;
    cout << "Output for m = 10, n = 4: " << numberSequence(m1, n1) << endl;

    int m2 = 5, n2 = 2;
    cout << "Output for m = 5, n = 2: " << numberSequence(m2, n2) << endl;

    return 0;
}
