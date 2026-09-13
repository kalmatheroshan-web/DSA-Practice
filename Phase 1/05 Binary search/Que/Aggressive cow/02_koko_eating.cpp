#include <bits/stdc++.h>
using namespace std;

/*
    Koko loves to eat bananas.

    We need to find the MINIMUM eating speed "k"
    such that Koko can finish all piles within h hours.

    Example:
    piles = {3, 6, 7, 11}
    h = 8

    Answer = 4

    At speed 4:
        3  -> 1 hour
        6  -> 2 hours
        7  -> 2 hours
        11 -> 3 hours

        Total = 1 + 2 + 2 + 3 = 8 hours
*/

// Check if Koko can finish all bananas
// when her eating speed is "speed".
bool canFinish(const vector<int> &piles, int h, int speed)
{
    long long hours = 0;

    for (int bananas : piles)
    {
        // ceil(bananas / speed)
        hours += (bananas + speed - 1) / speed;

        // No need to continue if already too slow
        if (hours > h)
            return false;
    }

    return true;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    // Smallest possible speed
    int start = 1;

    // Largest useful speed = largest pile
    int end = *max_element(piles.begin(), piles.end());

    int answer = end;

    while (start <= end)
    {
        int speed = start + (end - start) / 2;

        if (canFinish(piles, h, speed))
        {
            // This speed works.
            // But maybe an even smaller speed can work.
            answer = speed;
            end = speed - 1;
        }
        else
        {
            // This speed is too slow.
            // We need a bigger speed.
            start = speed + 1;
        }
    }

    return answer;
}

int main()
{
    vector<int> piles = {3, 6, 7, 11};
    int hours = 8;

    int answer = minEatingSpeed(piles, hours);

    cout << "Minimum eating speed = " << answer << endl;

    return 0;
}