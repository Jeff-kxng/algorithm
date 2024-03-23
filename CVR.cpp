/*
Problem: LAB.02.04 - Capacitaed Vehicle Routing
Description
A fleet of K identical trucks having capacity Q need to be scheduled to delivery pepsi packages from a central depot 0 to clients 1,2,…,n. Each client i requests d[i] packages. The distance from location i to location j is c[i,j], 0≤i,j≤n. A delivery solution is a set of routes: each truck is associated with a route, starting from depot, visiting some clients and returning to the depot for deliverying requested pepsi packages such that:
Each client is visited exactly by one route
Total number of packages requested by clients of each truck cannot exceed its capacity
Goal
Find a solution having minimal total travel distance
Note that:
There might be the case that a truck does not visit any client (empty route)
The orders of clients in a route is important, e.g., routes 0 -> 1 -> 2 -> 3 -> 0 and 0 -> 3-> 2 -> 1 -> 0 are different.
Input
Line 1: n,K,Q (2≤n≤12,1≤K≤5,1≤Q≤50)
Line 2: d[1],...,d[n](1≤d[i]≤10)
Line i+3 (i=0,…,n): the i
th
 row of the distance matrix c (1≤c[i,j]≤30)
Output
Minimal total travel distance
Example
Input
4 2 15
7 7 11 2
0 12 12 11 14
14 0 11 14 14
14 10 0 11 12
10 14 12 0 13
10 13 14 11 0

Output
70
 */
#include <iostream>
using namespace std;

#define MAX_N 30

int y[MAX_N + 1], x[MAX_N + 1], visited[MAX_N + 1], load[MAX_N + 1], d[MAX_N + 1];
int c[MAX_N + 1][MAX_N + 1], nbR = 0, segments = 0, n, K, Q, f = 0, f_s = 1000, cmin = 1000;

int checkX(int v, int k) {
    if (v > 0 && visited[v])
        return 0;
    if (load[k] + d[v] > Q)
        return 0;
    return 1;
}

void TRY_X(int s, int k) {
    if (s == 0) {
        if (k < K)
            TRY_X(y[k + 1], k + 1);
        return;
    }
    for (int v = 0; v <= n; v++) {
        if (checkX(v, k)) {
            x[s] = v;
            visited[v] = 1;
            f += c[s][v];
            load[k] += d[v];
            segments++;

            if (v > 0 && f + (n + nbR - segments) * cmin < f_s)
                TRY_X(v, k);
            else {
                if (k == K) {
                    if (segments == n + nbR)
                        f_s = (f_s < f + c[v][0]) ? f_s : f + c[v][0];
                } else {
                    if (f + (n + nbR - segments) * cmin < f_s)
                        TRY_X(y[k + 1], k + 1);
                }
            }

            visited[v] = 0;
            f -= c[s][v];
            load[k] -= d[v];
            segments--;
        }
    }
}

int checkY(int v, int k) {
    if (v == 0)
        return 1;
    if (load[k] + d[v] > Q)
        return 0;
    if (visited[v])
        return 0;
    return 1;
}

void TRY_Y(int k) {
    int s = 0;
    if (y[k - 1] > 0)
        s = y[k - 1] + 1;
    for (int v = s; v <= n; v++) {
        if (checkY(v, k)) {
            y[k] = v;
            if (v > 0)
                segments++;
            visited[v] = 1;
            f += c[0][v];
            load[k] += d[v];
            if (k < K)
                TRY_Y(k + 1);
            else {
                nbR = segments;
                TRY_X(y[1], 1);
            }
            load[k] -= d[v];
            visited[v] = 0;
            f -= c[0][v];
            if (v > 0)
                segments--;
        }
    }
}

void solve() {
    y[0] = 0;
    for (int v = 1; v <= n; v++)
        visited[v] = 0;
    TRY_Y(1);
}

int main() {
    cin >> n >> K >> Q;

    for (int i = 1; i <= n; i++)
        cin >> d[i];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> c[i][j];
            if (c[i][j] != 0)
                cmin = (cmin < c[i][j]) ? cmin : c[i][j];
        }
    }

    solve();
    cout << f_s;

    return 0;
}
