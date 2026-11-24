
#include <bits/stdc++.h>
using namespace std;

/*
Search element in 2D Matrix where

    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.

    Search for a target in a row-wise and column-wise
    sorted matrix using Staircase Search.

    Approach 1: Start from the top-right corner.
    Approach 2: Start from the bottom-left corner.
*/

// Approach 1: Start from the top-right corner
bool searchMatrixTopRight(vector<vector<int>> &matrix, int target) {
    int totalRows = matrix.size();
    int totalCols = matrix[0].size();

    int currentRow = 0;
    int currentCol = totalCols - 1;

    while (currentRow < totalRows && currentCol >= 0) {
        int currentElement = matrix[currentRow][currentCol];

        if (currentElement == target)
            return true;

        else if (currentElement > target)
            currentCol--; // Move left

        else
            currentRow++; // Move down
    }
    return false;
}

// Approach 2: Start from the bottom-left corner
bool searchMatrixBottomLeft(vector<vector<int>> &matrix, int target) {
    int totalRows = matrix.size();
    int totalCols = matrix[0].size();

    int currentRow = totalRows - 1;
    int currentCol = 0;

    while (currentRow >= 0 && currentCol < totalCols) {
        int currentElement = matrix[currentRow][currentCol];

        if (currentElement == target)
            return true;

        else if (currentElement > target)
            currentRow--; // Move up

        else
            currentCol++; // Move right
    }

    return false;
}

int main() {
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15},
                                  {2, 5, 8, 12, 19},
                                  {3, 6, 9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};

    int target = 16;

    cout << "Search (Top-Right): " << (searchMatrixTopRight(matrix, target) ? "Found" : "Not Found")
         << "\n";

    cout << "Search (Bottom-Left): "
         << (searchMatrixBottomLeft(matrix, target) ? "Found" : "Not Found") << "\n";

    return 0;
}
