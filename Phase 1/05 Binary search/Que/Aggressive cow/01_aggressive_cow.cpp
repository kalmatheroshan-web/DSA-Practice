#include <bits/stdc++.h>

    using namespace std;

/*
============================================================
AGGRESSIVE COWS
============================================================

Given:

    A set of stalls represented by their positions.

We have to place 'k' cows in the stalls such that:

    The minimum distance between any two cows is as large
    as possible.

Example:

    stalls = {1, 2, 4, 5, 10}
    k = 3

Possible placement:

    Cow 1 -> 1
    Cow 2 -> 4
    Cow 3 -> 10

Distances:

    4 - 1  = 3
    10 - 4 = 6

Minimum distance = 3

But we can do better:

    Cow 1 -> 1
    Cow 2 -> 5
    Cow 3 -> 10

Distances:

    5 - 1  = 4
    10 - 5 = 5

Minimum distance = 4

Therefore:

    Answer = 4

============================================================
MAIN IDEA
============================================================

This is a:

    MAX(MIN)

problem.

We want to:

    MAXIMIZE the minimum distance.


Instead of directly finding the answer, we ask:

    "Can I place k cows such that the minimum distance
     between cows is at least 'dist'?"


This is called a:

    FEASIBILITY CHECK


If a distance is possible:

    try a larger distance


If a distance is not possible:

    try a smaller distance


Therefore, we can use:

    BINARY SEARCH ON ANSWER


============================================================
*/

// ============================================================
// Feasibility Function
//
// Checks whether we can place 'k' cows such that the minimum
// distance between any two cows is at least 'minDistance'.
//
// Time Complexity: O(N)
// Space Complexity: O(1)
// ============================================================

bool canPlaceCows(const vector<int> &stalls, int k, int minDistance)
{
    int count = 1;

    // First cow is placed at the first stall.
    int lastPosition = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
        // If this stall is far enough from the last cow,
        // place another cow here.
        if (stalls[i] - lastPosition >= minDistance)
        {
            count++;
            lastPosition = stalls[i];

            // We successfully placed all k cows.
            if (count == k)
            {
                return true;
            }
        }
    }

    return false;
}

// ============================================================
// Brute Force Approach
//
// Try every possible minimum distance.
//
// Time Complexity:
//     O(N log N) for sorting
//     + O(N * maxDistance)
//
// Overall:
//     O(N log N + N * maxDistance)
//
// Space Complexity: O(1) apart from sorting implementation
// ============================================================

int aggressiveCowsBruteForce(vector<int> stalls, int k)
{
    int n = stalls.size();

    if (k > n)
    {
        return -1;
    }

    // Sort stall positions.
    sort(stalls.begin(), stalls.end());

    // Minimum possible distance = 1
    //
    // Maximum possible distance =
    // last stall - first stall

    int maxDistance = stalls[n - 1] - stalls[0];

    int answer = -1;

    // Try every possible minimum distance.
    for (int minDistance = 1;
         minDistance <= maxDistance;
         minDistance++)
    {
        if (canPlaceCows(stalls, k, minDistance))
        {
            // This distance is possible.
            answer = minDistance;
        }
        else
        {
            // If this distance is not possible,
            // larger distances will also not be possible.
            break;
        }
    }

    return answer;
}

/*
============================================================
BINARY SEARCH APPROACH
============================================================

Example:

    stalls = {1, 2, 4, 5, 10}
    k = 3


After sorting:

    {1, 2, 4, 5, 10}


Possible answer range:

    start = 1

    end = 10 - 1
        = 9


So:

    [1 ........ 9]


Suppose:

    mid = 5


Question:

    Can we place 3 cows with minimum distance >= 5?


Try greedily:

    Cow 1 -> 1

    Next possible stall:
        1 -> 2  distance = 1  X
        1 -> 4  distance = 3  X
        1 -> 5  distance = 4  X
        1 -> 10 distance = 9  YES

    Cow 2 -> 10


Only 2 cows can be placed.

Therefore:

    distance = 5 is NOT possible.


So we search the left side:

    end = mid - 1


Now suppose:

    mid = 4


Can we place 3 cows with minimum distance >= 4?


    Cow 1 -> 1

    Cow 2 -> 5
        distance = 4

    Cow 3 -> 10
        distance = 5


YES!


Therefore:

    distance = 4 is possible.


Since we want to MAXIMIZE the minimum distance,
try something larger:

    start = mid + 1


This is the important binary-search pattern:

    POSSIBLE
        -> move RIGHT
        -> try a larger answer

    NOT POSSIBLE
        -> move LEFT
        -> try a smaller answer


============================================================
*/

// ============================================================
// Binary Search Approach
//
// Time Complexity:
//     O(N log N) for sorting
//     O(log(maxDistance)) binary-search iterations
//     O(N) feasibility check per iteration
//
// Overall:
//     O(N log N + N log(maxDistance))
//
// Space Complexity:
//     O(1) apart from sorting implementation
// ============================================================

int aggressiveCows(vector<int> stalls, int k)
{
    int n = stalls.size();

    if (k > n)
    {
        return -1;
    }

    // Sort stall positions.
    sort(stalls.begin(), stalls.end());

    // --------------------------------------------------------
    // Search Space
    // --------------------------------------------------------

    int start = 1;

    int end = stalls[n - 1] - stalls[0];

    int answer = -1;

    // --------------------------------------------------------
    // Binary Search
    // --------------------------------------------------------

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        // Can we place k cows with at least 'mid'
        // distance between them?
        if (canPlaceCows(stalls, k, mid))
        {
            // YES:
            // mid is a possible answer.
            //
            // But we want the maximum possible distance,
            // so try something larger.

            answer = mid;

            start = mid + 1;
        }
        else
        {
            // NO:
            // mid is too large.
            //
            // Try a smaller distance.

            end = mid - 1;
        }
    }

    return answer;
}

int main()
{
    // Example 1
    //
    // vector<int> stalls = {8, 1, 2, 4, 9};

    // Example 2
    vector<int> stalls = {1, 2, 4, 5, 10};

    int k = 3;

    // --------------------------------------------------------
    // Brute Force
    // --------------------------------------------------------

    cout << "Brute Force Answer : "
         << aggressiveCowsBruteForce(stalls, k)
         << endl;

    // --------------------------------------------------------
    // Binary Search
    // --------------------------------------------------------

    cout << "Binary Search Answer : "
         << aggressiveCows(stalls, k)
         << endl;

    return 0;
}