#include <bits/stdc++.h>
using namespace std;

/*
You are given an array arr[] containing positive integers.
The elements in the array arr[] range from 1 to n (where n is the size of the array),
and some numbers may be repeated or absent.
You have to count the frequency of all numbers in the range 1 to n
and return an array of size n such that result[i] represents
the frequency of the number (i+1) (1-based indexing).

Example:
Input: arr[] = [2, 3, 2, 3, 5]
Output: [0, 2, 2, 0, 1]

Input: arr[] = [3, 3, 3, 3]
Output: [0, 0, 4, 0]
*/

vector<int> frequencyCount(vector<int> &ar)
{

    int n = ar.size();
    for (int i = 0; i < n; i++)
    {
        ar[i]--;
        int inx = ar[i] % n;
        ar[inx] += n;
    }

    vector<int> ans;
    for (int val : ar)
    {
        ans.push_back(val / n);
    }
    return ans;
}
int main()
{

    vector<int> ar = {2, 3, 2, 3, 5};
    // vector<int> ar = {3, 3, 3, 3};

    vector<int> res = frequencyCount(ar);

    cout << "Frequencies: ";
    for (int x : res)
        cout << x << " ";
    cout << endl;

    return 0;
}
