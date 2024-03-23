/*
Problem: LAB.01.01 - Telco data check & query
Description
Write a C program to perform some queries on a telco data (comming from stdin) with the following format:
The first block of data consists of lines (terminated by a line containing #), each line (number of lines can be up to 100000) is under the form:
        call <from_number> <to_number> <date> <from_time> <end_time>
which is a call from the phone number <from_number> to a phone number <to_number> on <date>, and starting at time-point <from_time>, terminating at time-point <end_time>
<from_number> and <to_number> are string of 10 characters (a phone number is correct if it contains only digits 0,1,...,9, otherwise, the phone number is incorrect)
<date> is under the form YYYY-MM-DD (for example 2022-10-21)
<from_time> and <to_time> are under the form hh:mm:ss (for example, 10:07:23)

The second block consists of queries (terminated by a line containing #), each query in a line (number of lines can be up to 100000) and belongs to one of the following types:
?check_phone_number: print to stdout (in a new line) value 1 if no phone number is incorrect
?number_calls_from <phone_number>: print to stdout (in a new line) the number of times a call is made from <phone_number>
?number_total_calls: print to stdout (in a new line) the total number of calls of the data
?count_time_calls_from <phone_number>: print to stdout (in a new line) the total time duration (in seconds) the calls are made from <phone_number>

Example
Input
call 0912345678 0132465789 2022-07-12 10:30:23 10:32:00
call 0912345678 0945324545 2022-07-13 11:30:10 11:35:11
call 0132465789 0945324545 2022-07-13 11:30:23 11:32:23
call 0945324545 0912345678 2022-07-13 07:30:23 07:48:30
#
?check_phone_number
?number_calls_from 0912345678
?number_total_calls
?count_time_calls_from 0912345678
?count_time_calls_from 0132465789
#

Output
1
2
4
398
120
 */
#include <bits/stdc++.h>

using namespace std;

bool isValidPhoneNumber(const string &s)
{
    if (s.length() != 10)
        return false;
    return all_of(s.begin(), s.end(), [](char c) { return isdigit(c); });
}

int calculateCallDuration(const string &ftime, const string &etime)
{
    int startTime = stoi(ftime.substr(0, 2)) * 3600 + stoi(ftime.substr(3, 2)) * 60 + stoi(ftime.substr(6, 2));
    int endTime = stoi(etime.substr(0, 2)) * 3600 + stoi(etime.substr(3, 2)) * 60 + stoi(etime.substr(6, 2));
    return endTime - startTime;
}

map<string, int> numberCalls;
map<string, int> timeCall;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string type;
    int totalCalls = 0;
    int incorrectPhone = 0;

    while (cin >> type && type != "#")
    {
        ++totalCalls;
        string fnum, tnum, date, ftime, etime;
        cin >> fnum >> tnum >> date >> ftime >> etime;

        if (!isValidPhoneNumber(fnum) || !isValidPhoneNumber(tnum))
            ++incorrectPhone;

        numberCalls[fnum]++;
        timeCall[fnum] += calculateCallDuration(ftime, etime);
    }

    while (cin >> type && type != "#")
    {
        if (type == "?check_phone_number")
        {
            cout << !incorrectPhone << endl;
        }
        else if (type == "?number_calls_from")
        {
            string phone;
            cin >> phone;
            cout << numberCalls[phone] << endl;
        }
        else if (type == "?number_total_calls")
        {
            cout << totalCalls << endl;
        }
        else if (type == "?count_time_calls_from")
        {
            string phone;
            cin >> phone;
            cout << timeCall[phone] << endl;
        }
    }

    return 0;
}
