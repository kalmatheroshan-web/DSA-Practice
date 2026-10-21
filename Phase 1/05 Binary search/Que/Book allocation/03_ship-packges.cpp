#include <bits/stdc++.h>
using namespace std;

/*
Problem in Simple Words:

    -- You are given an array of weights, where each element is the weight of a package.
    --
    -- Packages must be shipped in order (you can’t rearrange them).
    --
    -- You have a ship that can carry a certain capacity per day.
    --
    -- You want to ship all packages within D days.

👉 Find the minimum ship capacity needed to do this.


Rules:
Remember that: weights are not sorted, and you cannot change the order of packages.

You can load packages one by one in the given order.

    -If the next package doesn’t fit in the remaining capacity of the day, the ship sails, and you continue on the next day.

    -You must finish shipping all packages within exactly D days or less.

*/

bool isPossible(const vector<int> &ar, int days, int capacity)
{
    int requiredDays = 1, currentLoad = 0;
    for (int w : ar)
    {
        if (currentLoad + w > capacity)
        {
            requiredDays++; // start new day
            currentLoad = 0;
        }
        currentLoad += w;
    }
    return requiredDays <= days;
}

// brute force approach
int shipWithinDays(vector<int> &ar, int days)
{
    int n = ar.size() - 1;

    int minimum = 0;
    int maximum = 0;

    for (int load : ar)
    {
        minimum = max(minimum, load);
        maximum += load;
    }

    int ans = maximum;

    for (int i = minimum; i <= maximum; i++)
    {
        if (isPossible(ar, days, i))
        {
            ans = i;
            break;
        }
    }

    return ans;
}

int shipWithinDays(vector<int> &weights, int days)
{
    int low = 0, high = 0, answer = -1;

    // Find the search range
    for (int w : weights)
    {
        low = max(low, w); // min capacity must be at least the heaviest package
        high += w;         // max capacity could be sum of all weights
    }

    while (low <= high)
    {
        int mid = low + (high - low) / 2; // trial capacity

        if (isPossible(weights, days, mid))
        {
            answer = mid; // capacity works, try smaller
            high = mid - 1;
        }
        else
            low = mid + 1; // capacity too small, increase it
    }

    return answer;
}

int main()
{
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    cout << "Minimum ship capacity: " << shipWithinDays(weights, days) << endl;
    return 0;
}
