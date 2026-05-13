#include <bits/stdc++.h>
using namespace std;

/*
Approach:

    max(min)


*/

// Brute Force
int aggresive(vector<int> ar, int k)
{
    int n = ar.size();
    if (k > n)
        return -1;
        
    sort(ar.begin(), ar.end());

    int mini = (ar[n - 1] - ar[0]);

    int ans = -1;
    for (int min_inx = 1; min_inx <= mini; min_inx++)
    {
        int dis = min_inx, cnt = 1;
        int j = 1, temp = k, cur = ar[0];

        while (j < n && temp > 1)
        {
            if (ar[j] - cur >= dis)
            {
                cnt++;
                cur = ar[j];
                temp--;
            }
            j++;
        }

        if (cnt == k)
            ans = min_inx;
        else
            break;
    }
    return ans;
}

// Binary Search
int aggressiveCows(vector<int> ar, int k)
{
    int n = ar.size();
    if (k > n)
        return -1;

    sort(ar.begin(), ar.end());

    int s = 1, e = (ar[n - 1] - ar[0]);

    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        int dis = mid, cnt = 1;
        int j = 1, temp = k, cur = ar[0];

        while (j < n && temp > 1)
        {
            if (ar[j] - cur>= dis)
            {
                cnt++;
                cur = ar[j];
                temp--;
            }
            j++;
        }

        if (cnt == k)
        {
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return ans;
}
int main()
{
    // vector<int> ar = {8, 1, 2, 4, 9};
    vector<int> ar = {1, 2, 4, 5, 10};
    int k = 3;
    cout << aggresive(ar, k) << endl;
}