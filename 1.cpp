#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxNumMeetings(int start[], int end[], int N) {
    vector<pair<int, int>> meetings;
    int count = 0;
    int lastEndTime = 0;
    for (int i = 0; i < N; i++) {
        meetings.push_back({ end[i], start[i] });
    }
    for (int i = 0; i < N; i++) {
        if (meetings[i].second > lastEndTime) {
            count++;
            lastEndTime = meetings[i].first;
        }
    }
    return count;
}

int main() {
    int N_first = 6;
    int first[] = { 1, 3, 0, 5, 8, 5 };
    int end_first[] = { 2, 4, 6, 7, 9, 9 };
    cout << "Maximum number of meetings for first example is  " << maxNumMeetings(first, end_first, N_first) << endl;
    int N_second = 3;
    int second[] = { 10, 12, 20 };
    int end_second[] = { 20, 25, 30 };
    cout << "Maximum number of meetings for second example is " << maxNumMeetings(second, end_second, N_second) << endl;
    return 0;
}