#include <bits/stdc++.h>
using namespace std;

int longest_sub(vector<int> &ar, int k)
{
    int n = ar.size();
    int maxi_len = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += ar[j];
            if (sum <= k)
                maxi_len = max(maxi_len, j - i + 1);
            else
                break;
        }
    }
    return maxi_len;
}
/*
    time : O(N*N)
    space : O(1)
*/

int longest_sub2(vector<int> &ar, int k)
{
    int left = 0, right = 0;

    /*
       expand = right++
       shrink = left++
    */

    int n = ar.size();
    int maxi_len = 0, sum = 0;

    while (right < n)
    {
        sum += ar[right];

        // shrink
        while (sum > k)
            sum -= ar[left], left++;

        if (sum <= k)
            maxi_len = max(maxi_len, right - left + 1);

        // expend
        right++;
    }

    return maxi_len;
}
/*
    time : O(N+N)
    space : O(1)
*/

int longest_sub3(vector<int> &ar, int k)
{
    int maxi_len = 0, sum = 0;
    int left = 0, right = 0;

    int n = ar.size();

    while (right < n)
    {
        sum += ar[right];
        int current_len = right - left + 1;

        // valid
        if (sum <= k)
            maxi_len = max(maxi_len, current_len);

        // invalid
        else if (sum > k)
            left++;

        right++;
    }

    return maxi_len;
}
/*
    time : O(N)
    space : O(1)
*/

int main()
{
    vector<int> ar = {2, 5, 1, 7, 10};
    int k = 14;

    cout << "Brute Force : " << longest_sub(ar, k) << endl;
    cout << "Better :  " << longest_sub2(ar, k) << endl;
    cout << "Optimized : " << longest_sub3(ar, k) << endl;
    return 0;
}
