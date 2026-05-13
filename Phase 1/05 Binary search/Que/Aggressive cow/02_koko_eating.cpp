#include <bits/stdc++.h>
using namespace std;
/*

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

            ************
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
            ************
            
Return the minimum integer k such that she can eat all the bananas within h hours.


*/
int minEatingSpeed(vector<int> &piles, int h)
{
    sort(piles.begin(), piles.end());

    int n = piles.size();
    int s = 1, e = piles[n - 1];
    int ans = 0;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        long long calc_h = 0;

        for (int val : piles)
        {
            calc_h += ceil((double)val / mid);
            if (calc_h > h)
                break;
        }

        if (calc_h > h)
            s = mid + 1;
        else
        {
            ans = mid;
            e = mid - 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> piles = {3, 6, 7, 11};
    int hours = 8;

    int answer = minEatingSpeed(piles, hours);
    cout << "The minimum time it will be take to finish banana " << answer << endl;
}