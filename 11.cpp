#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isFeasible(int arr[], int n, int m, int mid) {
    int studentsRequired = 1;
    int pagesAllocated = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i] > mid)
            return false;

        if (pagesAllocated + arr[i] > mid) {
            studentsRequired++;
            pagesAllocated = arr[i];

            if (studentsRequired > m)
                return false;
        } else {
            pagesAllocated += arr[i];
        }
    }

    return true;
}

int findPages(int arr[], int n, int m) {
    if (n < m)
        return -1;

    int sum = 0, maxPage = 0;

    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        maxPage = max(maxPage, arr[i]);
    }

    int low = maxPage, high = sum, result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (isFeasible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int N = 3;
    int A[] = {15, 17, 20};
    int M = 2;
    cout << "Result = " << findPages(A, N, M) << endl;
    return 0;
}
