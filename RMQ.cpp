/*
Problem: LAB.01.03 - Range Minimum Query
Description
Given a sequence of n integers a
0
,. . .,a
n-1
. We denote rmq(i,j) the minimum element of the sequence a
i
, a
i+1
, . . .,a
j
. Given m pairs (i
1
, j
1
),. . .,(i
m
, j
m
), compute the sum Q = rmq(i
1
,j
1
) + . . . + rmq(i
m
, j
m
)
Input
Line 1: n (1 <=  n <= 10
6
)
Line 2: a
0
, . . . ,a
n-1
 ( 1  <=  ai <= 10
6
)
line 3: m (1  <= m <= 10
6
)
Line k+3 (k=1, . . ., m): i
k
, j
k
 (0  <=  i
k
 < j
k
 < n)
Output
Write the value Q
Example
Input
16
2 4 6 1 6 8 7 3 3 5 8 9 1 2 6 4
4
1 5
0 9
1 15
6 10

Output
6
 */
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 5;
const int LOGN = 20;

int a[maxN];
int st[maxN][LOGN];

void buildSparseTable(int n) {
    for (int i = 0; i < n; ++i)
        st[i][0] = a[i];

    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 0; i + (1 << j) <= n; ++i) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r) {
    int k = log2(r - l + 1);
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    buildSparseTable(n);

    cin >> m;
    int ans = 0;
    while (m--) {
        int i, j;
        cin >> i >> j;
        ans += query(i, j);
    }

    cout << ans << "\n";
    return 0;
}
