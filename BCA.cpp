/*
Problem: LAB.02.01 - Balanced Courses Assignments
Description
At the beginning of the semester, the head of a computer science department D have to assign courses to teachers in a balanced way. The department D has m teachers T={1,2,...,m} and n courses C={1,2,...,n}. Each teacher t∈T has a preference list which is a list of courses he/she can teach depending on his/her specialization. We known a list of pairs of conflicting two courses that cannot be assigned to the same teacher as these courses have been already scheduled in the same slot of the timetable. The load of a teacher is the number of courses assigned to her/him. How to assign nn courses to mm teacher such that each course assigned to a teacher is in his/her preference list, no two conflicting courses are assigned to the same teacher, and the maximal load is minimal.
Input
The input consists of following lines
Line 1: contains two integer m and n (1≤m≤10, 1≤n≤30)
Line i+1: contains an positive integer k and k positive integers indicating the courses that teacher i can teach (∀i=1,…,m)
Line m+2: contains an integer k
Line i+m+2: contains two integer i and j indicating two conflicting courses (∀i=1,…,k)
Output
The output contains a unique number which is the maximal load of the teachers in the solution found and the value -1 if not solution found.
Example
Input
4 12
5 1 3 5 10 12
5 9 3 4 8 12
6 1 2 3 4 9 7
7 1 2 3 5 6 10 11
25
1 2
1 3
1 5
2 4
2 5
2 6
3 5
3 7
3 10
4 6
4 9
5 6
5 7
5 8
6 8
6 9
7 8
7 10
7 11
8 9
8 11
8 12
9 12
10 11
11 12

Output
3
 */
#include <bits/stdc++.h>
using namespace std;

int m, n;
unordered_map<int, set<int>> c_to_t;
unordered_map<int, vector<int>> c_conflict;
int sol[31];
int result = -1;
int load[10];

int max_load() {
    int res = 0;
    for (int i = 0; i < m; i++) {
        if (load[i] > res) res = load[i];
    }
    return res;
}

void backtrack(int k) {
    if (max_load() >= result && result != -1) return;
    if (k > n) {
        int maxload = max_load();
        if (maxload < result || result == -1) {
            result = maxload;
        }
        return;
    }
    for (int teacher : c_to_t[k]) {
        sol[k - 1] = teacher;
        load[teacher]++;
        vector<int> reverse_course;
        for (int course : c_conflict[k]) {
            if (!c_to_t[course].count(teacher)) continue;
            c_to_t[course].erase(teacher);
            reverse_course.push_back(course);
            if (c_to_t[course].empty()) goto reverse;
        }
        backtrack(k + 1);
        reverse:
        for (int course : reverse_course) {
            c_to_t[course].insert(teacher);
        }
        sol[k - 1] = -1;
        load[teacher]--;
    }
}

int main() {
    int k, ct, ctc;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> ct;
            c_to_t[ct].insert(i);
        }
    }
    fill(sol, sol + n + 1, -1);
    fill(load, load + m, 0);
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> ct >> ctc;
        c_conflict[ct].push_back(ctc);
        c_conflict[ctc].push_back(ct);
    }
    backtrack(1);
    cout << result;
    return 0;
}
