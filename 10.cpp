#include <iostream>
#include <vector>

using namespace std;

int kthElement(int arr1[], int arr2[], int n, int m, int k) {
    int i = 0, j = 0, count = 0;
    int result;

    while (i < n && j < m && count < k) {
        if (arr1[i] < arr2[j])
            result = arr1[i++];
        else
            result = arr2[j++];
        count++;
    }

    if (count == k)
        return result;

    while (i < n && count < k) {
        result = arr1[i++];
        count++;
    }
    while (j < m && count < k) {
        result = arr2[j++];
        count++;
    }

    return result;
}

int main() {
    int arr1[] = {2, 3, 6, 7, 9};
    int arr2[] = {1, 4, 8, 10};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    int k = 5;

    cout << "Output: " << kthElement(arr1, arr2, n, m, k) << endl;

    return 0;
}
