#include <bits/stdc++.h>
using namespace std;

/*

Given an array arr[] where each element denotes the length of a board, and an integer k representing the number of painters available. Each painter takes 1 unit of time to paint 1 unit length of a board.

Determine the minimum amount of time required to paint all the boards, under the constraint that each painter can paint only a contiguous sequence of boards (no skipping or splitting allowed).

*/

int minTime(vector<int> &ar, int k)
{
    // code here
    int s = -1, e = 0;
    for (int val : ar)
    {
        if (val > s)
            s = val;
        e += val;
    }

    int ans = -1;

    while (s <= e)
    {
        int mid = e + (s - e) / 2;
        int cnt = 1, sum = 0;

        for (int val : ar)
        {
            sum += val;
            if (sum > mid)
            {
                cnt++;
                sum = val;
            }
        }
        if (cnt <= k)
            ans = mid, e = mid - 1;
        else
            s = mid + 1;
    }

    return ans;
}

int main()
{
    vector<int> ar = {5, 10, 30, 20, 15};
    int k = 3;
    int time = minTime(ar, k);

    cout << "Time taken to paint is " << time << endl;
}