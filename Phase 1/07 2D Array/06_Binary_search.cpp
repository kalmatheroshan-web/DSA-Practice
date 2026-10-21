#include <bits/stdc++.h>

using namespace std;

// ============================================================
// Print Matrix
// Time Complexity: O(row * col)
// Space Complexity: O(1)
// ============================================================

void printMatrix(const vector<vector<int>> &mat)
{
    for (const auto &row : mat)
    {
        for (const auto &val : row)
        {
            cout << val << " ";
        }

        cout << endl;
    }
}

// ============================================================
// Approach 1: Linear Search
//
// Works for any matrix.
//
// Time Complexity: O(row * col)
// Space Complexity: O(1)
// ============================================================

bool linearSearch(const vector<vector<int>> &ar, int x)
{
    int row = ar.size();
    int col = ar[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (ar[i][j] == x)
            {
                return true;
            }
        }
    }

    return false;
}

// ============================================================
// Approach 2: Binary Search in Each Row
//
// Assumption:
// Each individual row is sorted.
//
// Time Complexity: O(row * log(col))
// Space Complexity: O(1)
// ============================================================

bool binarySearchEachRow(const vector<vector<int>> &ar, int x)
{
    int row = ar.size();
    int col = ar[0].size();

    for (int i = 0; i < row; i++)
    {
        // Check whether x can possibly exist in this row.
        //
        // Example:
        // Row = {5, 6, 7, 8}
        //
        // If x = 6:
        // 5 <= 6 <= 8
        //
        // So perform binary search in this row.

        if (ar[i][0] <= x && x <= ar[i][col - 1])
        {
            int start = 0;
            int end = col - 1;

            while (start <= end)
            {
                int mid = start + (end - start) / 2;

                if (ar[i][mid] == x)
                {
                    return true;
                }

                if (ar[i][mid] > x)
                {
                    // x is on the left side
                    end = mid - 1;
                }
                else
                {
                    // x is on the right side
                    start = mid + 1;
                }
            }

            // x could only exist in this row because
            // x was within the row's minimum and maximum.
            // Since binary search failed, x is not present.
            return false;
        }
    }

    return false;
}

/*
============================================================
Approach 3: Binary Search on the Entire Matrix
============================================================

This approach works when the matrix is completely sorted like:

    { 1,  2,  3,  4}
    { 5,  6,  7,  8}
    { 9, 10, 11, 12}
    {13, 14, 15, 16}


Notice that if we imagine the matrix as a 1D array:

    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}


Then we can perform normal binary search.

The only problem is:

    We have a 1D index,
    but the actual matrix has row and column.

So we convert:

    1D index -> row and column


Suppose:

    row = 4
    col = 4

Then:

    index = 0  -> ar[0][0]
    index = 1  -> ar[0][1]
    index = 2  -> ar[0][2]
    index = 3  -> ar[0][3]

    index = 4  -> ar[1][0]
    index = 5  -> ar[1][1]
    index = 6  -> ar[1][2]
    index = 7  -> ar[1][3]

    index = 8  -> ar[2][0]
    ...


The formulas are:

    row_index = index / col
    col_index = index % col


Example:

    index = 6
    col = 4

    row_index = 6 / 4 = 1
    col_index = 6 % 4 = 2

Therefore:

    ar[1][2] = 7


============================================================
Binary Search
============================================================

Total number of elements:

    row * col

So:

    start = 0
    end = row * col - 1


At every step:

    mid = start + (end - start) / 2

Convert mid into matrix coordinates:

    r = mid / col
    c = mid % col

Then compare:

    ar[r][c] with x


Time Complexity:

    O(log(row * col))

Space Complexity:

    O(1)

============================================================
*/

bool binarySearchSortedMatrix(const vector<vector<int>> &ar, int x)
{
    int row = ar.size();
    int col = ar[0].size();

    int start = 0;
    int end = row * col - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        // Convert 1D index into 2D coordinates.
        int r = mid / col;
        int c = mid % col;

        if (ar[r][c] == x)
        {
            return true;
        }

        if (ar[r][c] > x)
        {
            // x is on the left side.
            end = mid - 1;
        }
        else
        {
            // x is on the right side.
            start = mid + 1;
        }
    }

    return false;
}
int main()
{
    vector<vector<int>> ar =
        {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}};

    int x = 6;

    // --------------------------------------------------------
    // Print Matrix
    // --------------------------------------------------------

    cout << "Matrix:" << endl;

    printMatrix(ar);

    // --------------------------------------------------------
    // Linear Search
    // --------------------------------------------------------

    cout << "\nLinear Search:" << endl;

    cout << x << " is present: "
         << linearSearch(ar, x)
         << endl;

    // --------------------------------------------------------
    // Binary Search in Each Row
    // --------------------------------------------------------

    cout << "\nBinary Search in Each Row:" << endl;

    cout << x << " is present: "
         << binarySearchEachRow(ar, x)
         << endl;

    // --------------------------------------------------------
    // Binary Search on Entire Matrix
    // --------------------------------------------------------

    cout << "\nBinary Search on Sorted Matrix:" << endl;

    cout << x << " is present: "
         << binarySearchSortedMatrix(ar, x)
         << endl;

    return 0;
}