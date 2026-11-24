#include <bits/stdc++.h>
using namespace std;

// moore voting algorithm

// if majority element always exits
int majorityElement(vector<int> &ar)
{
    int candidate = 0;
    int count = 0;

    // Phase 1 : Find candidate
    for (int val : ar)
    {
        if (count == 0)
        {
            candidate = val;
            count++;
        }
        else
        {
            if (candidate == val)
                count++;
            else
                count--;
        }
    }

    count = 0;

    // Phase 2 : calculate the candidate occur
    for (int val : ar)
        if (val == candidate)
            count++;
    return count > ar.size() / 2 ? candidate : -1;
}

int main()
{
    vector<int> ar1 = {3, 2, 3};
    vector<int> ar2 = {2, 2, 1, 1, 1, 2, 2};
    vector<int> ar3 = {1, 2, 3, 4};          // no majority
    vector<int> ar4 = {2, 2, 3, 3, 3, 4, 4}; // no majority

    cout << "Majority element in ar1: " << majorityElement(ar1) << "\n";
    cout << "Majority element in ar2: " << majorityElement(ar2) << "\n";
    cout << "Majority element in ar3: " << majorityElement(ar3) << "\n";
    cout << "Majority element in ar4: " << majorityElement(ar4) << "\n";
}