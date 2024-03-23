#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right) {
    int i, j, k;
    int inv_count = 0;

    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count = (inv_count + (mid - i)) % MOD;
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int mergeSort(vector<int> &arr, vector<int> &temp, int left, int right) {
    int mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;
        inv_count = mergeSort(arr, temp, left, mid) % MOD;
        inv_count = (inv_count + mergeSort(arr, temp, mid + 1, right) % MOD) % MOD;
        inv_count = (inv_count + merge(arr, temp, left, mid + 1, right) % MOD) % MOD;
    }
    return inv_count;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n), temp(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << mergeSort(arr, temp, 0, n - 1) % MOD << endl;
    return 0;
}
/*
Problem: LAB.03.02 - Inversion
Description
Given a sequence of integers a
1
, a
2
, ..., a
n
. A pair (i, j) is call an inversion if i < j and a
i
 > a
j
. Compute the number Q of inversions
Input
Line 1: contains a positive integer n (1 <= n <= 10
6
)
Line 2: contains a
1
, a
2
, ..., a
n
 (0 <= a
i
<= 10
6
)
Output
Write the value Q modulo 10
9
+7

Example
Input
6
3 2 4 5 6 1
Output
6
 */