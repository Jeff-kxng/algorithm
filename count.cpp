/*
Problem: LAB.02.01 - Count solutions to an integer linear equation
Description
Given a positive integer n and n positive integers a
1
, a
2
, ..., a
n
. Compute the number of positive integer solutions to the equation:
                          a
1
X
1
 + a
2
X
2
 + . . . + a
n
X
n
 = M

Input
Dòng 1: n và M
Dòng 2: a
1
, a
2
, ..., a
n
Output
   Số nghiệm nguyên dương
Ví dụ
Input
3 5
1 1 1
Output
6
 */
#include <iostream>
#include <vector>

using namespace std;

int countSolutions(int n, int M, vector<int>& coefficients, int index, int currentSum) {
    if (index == n) {
        return (currentSum == M);
    }

    int totalSolutions = 0;
    for (int i = 1; i <= M; ++i) {
        if (currentSum + i * coefficients[index] <= M) {
            totalSolutions += countSolutions(n, M, coefficients, index + 1, currentSum + i * coefficients[index]);
        } else {
            break;
        }
    }

    return totalSolutions;
}

int main() {
    int n, M;
    cin >> n >> M;

    vector<int> coefficients(n);
    for (int i = 0; i < n; ++i) {
        cin >> coefficients[i];
    }

    int solutions = countSolutions(n, M, coefficients, 0, 0);
    cout << solutions << endl;

    return 0;
}
