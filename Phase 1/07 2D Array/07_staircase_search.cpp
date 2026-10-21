#include <bits/stdc++.h>
using namespace std;

/*
   Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix.
   This matrix has the following properties:

   - Integers in each row are sorted in ascending from left to right.
   - Integers in each column are sorted in ascending from top to bottom.

   Staircase Search Approaches:

   -- Approach 1: Start from top-right corner
   -- Approach 2: Start from bottom-left corner
*/

// Approach 1: Start from top-right corner
bool searchMatrixTopRight(vector<vector<int>> &ar, int x)
{
    int row = ar.size();
    int col = ar[0].size();
    int ri = 0, ci = col - 1; // top-right corner

    while (ri < row && ci >= 0)
    {
        int ele = ar[ri][ci];
        if (ele == x)
            return true;
        else if (ele > x)
            ci--; // move left
        else
            ri++; // move down
    }
    return false;
}

// Approach 2: Start from bottom-left corner
bool searchMatrixBottomLeft(vector<vector<int>> &ar, int x)
{
    int row = ar.size();
    int col = ar[0].size();
    int ri = row - 1, ci = 0; // bottom-left corner

    while (ri >= 0 && ci < col)
    {
        int ele = ar[ri][ci];
        if (ele == x)
            return true;
        else if (ele > x)
            ri--; // move up
        else
            ci++; // move right
    }
    return false;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};

    int target = 16;

    cout << "Search (Top-Right): "
         << (searchMatrixTopRight(mat, target) ? "Found" : "Not Found") << "\n";

    cout << "Search (Bottom-Left): "
         << (searchMatrixBottomLeft(mat, target) ? "Found" : "Not Found") << "\n";

    return 0;
}
