#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>  

using namespace std;

int findMaxDeadline(const vector<tuple<int, int, int>>& jobs) {
    int maxDeadline = 0;
    for (const auto& job : jobs) {
        maxDeadline = max(maxDeadline, get<1>(job));
    }
    return maxDeadline;
}

vector<int> JobScheduling(int N, vector<tuple<int, int, int>> jobs) {
    sort(jobs.begin(), jobs.end(), [](const auto& a, const auto& b) {
        return get<2>(a) > get<2>(b);
        });
    int maxDeadline = findMaxDeadline(jobs);
    vector<bool> slot(maxDeadline + 1, false);  
    int countJobs = 0, totalProfit = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = min(maxDeadline, get<1>(jobs[i])); j > 0; --j) {
            if (!slot[j]) {  
                slot[j] = true; 
                totalProfit += get<2>(jobs[i]);  
                countJobs++;
                break;
            }
        }
    }
    return { countJobs, totalProfit };
}

int main() {
    vector<tuple<int, int, int>> jobs1 = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };
    auto result1 = JobScheduling(4, jobs1);
    cout << "Done jobs = " << result1[0] << ", Max profit =" << result1[1] << endl;
    vector<tuple<int, int, int>> jobs2 = { {1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15} };
    auto result2 = JobScheduling(5, jobs2);
    cout << "Done jobs = " << result2[0] << ", Max profit =" << result2[1] << endl;
    return 0;
}