#include <bits/stdc++.h>
using namespace std;

bool isFeasible(int mid, int arr[], int n, int c) {
    int pos = arr[0];
    int elements = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] - pos >= mid) {
            pos = arr[i];
            elements++;
            if (elements == c)
                return true;
        }
    }
    return false;
}

int largestMinDist(int arr[], int n, int c) {
    int left = 0;
    int right = arr[n-1] - arr[0];
    int max_dist = -1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isFeasible(mid, arr, n, c)) {
            max_dist = mid;
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return max_dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr+n);
        cout << largestMinDist(arr, n, c) << endl;
    }
    return 0;
}
/*
Problem: LAB.03.03 - Max-Distance Sub-Sequence
Description
Given N elements (2≤ N ≤100,000) on a straight line at positions x
1
,…, x
N
 (0≤ x
i
≤1,000,000,000).
The distance of a subset of N elements is defined to be the minimum distance between two elements.
Find the subset of N given elements containing exactly C elements such that the distance is maximal.
Input
The first line contains a positive integer T (1 <= T <= 20) which is the number of test cases.
Subsequent lines are T test cases with the following format:
Line 1: Two space-separated integers: N and C
Lines 2: contains  x1, x
2
, . . . , x
N

Output
For each test case output one integer: the distance of the subset found.

Example
input
1
5 3
1
2
8
4
9
output
3

Explain: Jonh can put his 3 cows in the stalls at positions 1, 4 and 8, resulting in a minimum distance of 3.
 */
