#include <bits/stdc++.h>
using namespace std;

// time O(N) space O(N)
int maxOccur(vector<int> &ar)
{

    // count using hashmap

    unordered_map<int, int> mp; //ele cnt

    for (int val : ar)
    {
        mp[val]++;
    }

    int ans = 0;
    int maxi = INT_MIN;

    for (auto val : mp)
    {
        int cur = val.second;
        if (maxi < cur)
        {
            maxi = cur;
            ans = val.first;
        }
    }
    return ans;
}

int main()
{

    vector<int> ar = {
        1,
        3,
        3,
        3,
        2,
        15,
        15,
        15,
        15,
        15,
        15,
        15,
    };

    int max_occur = maxOccur(ar);

    cout << "Majority Element is " << max_occur << endl;

    return 0;
}