
#include <bits/stdc++.h>
using namespace std;

/*
    Problem: 36. Valid Sudoku

    Description:
    Determine whether a 9x9 Sudoku board is valid.

    Rules:
    1. Every row must contain no duplicate digits from 1 to 9.
    2. Every column must contain no duplicate digits from 1 to 9.
    3. Every 3x3 box must contain no duplicate digits from 1 to 9.

    Note:
    - Empty cells are represented by '.'.
    - The board does not need to be completely filled.
    - Only the filled cells need to be validated.

    Approach 1: Three Separate Traversals
    -------------------------------------
    1. Check every row using a set.
    2. Check every column using a set.
    3. Check every 3x3 box using a set.

    Approach 2: Single Traversal
    ---------------------------
    Maintain three arrays of sets:
    - row[i] stores digits found in row i.
    - col[j] stores digits found in column j.
    - box[b] stores digits found in box b.

    For every cell, check all three sets before inserting
    the digit.

    Box Index Formula:
        b = (i / 3) * 3 + (j / 3)

    Time Complexity:
        O(N^2) for a fixed-size Sudoku board.
        O(N^2 log N) for a generalized board using sets.

    Auxiliary Space:
        O(1) for a fixed-size Sudoku board.
        O(N) for a generalized board.
*/


// Approach 1: Three Separate Traversals

class Solution1 {
public:
    bool isValidSudoku(vector<vector<char>>& ar) {

        // Check rows
        for (int i = 0; i < 9; i++) {
            set<char> s;

            for (int j = 0; j < 9; j++) {
                char ele = ar[i][j];

                if (ele == '.')
                    continue;

                if (s.find(ele) != s.end())
                    return false;

                s.insert(ele);
            }
        }

        // Check columns
        for (int i = 0; i < 9; i++) {
            set<char> s;

            for (int j = 0; j < 9; j++) {
                char ele = ar[j][i];

                if (ele == '.')
                    continue;

                if (s.find(ele) != s.end())
                    return false;

                s.insert(ele);
            }
        }

        // Check every 3x3 box
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                set<char> s;

                for (int k = i; k < i + 3; k++) {
                    for (int n = j; n < j + 3; n++) {
                        char ele = ar[k][n];

                        if (ele == '.')
                            continue;

                        if (s.find(ele) != s.end())
                            return false;

                        s.insert(ele);
                    }
                }
            }
        }

        return true;
    }
};


// Approach 2: Single Traversal Using Three Arrays of Sets

class Solution2 {
public:
    bool isValidSudoku(vector<vector<char>>& ar) {

        set<char> row[9], col[9], box[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char ch = ar[i][j];

                if (ch == '.')
                    continue;

                // Find the corresponding 3x3 box
                int b = (i / 3) * 3 + (j / 3);

                // Check for duplicates
                if (row[i].count(ch) ||
                    col[j].count(ch) ||
                    box[b].count(ch))
                    return false;

                // Store the digit in all three sets
                row[i].insert(ch);
                col[j].insert(ch);
                box[b].insert(ch);
            }
        }

        return true;
    }
};


int main() {

    return 0;
}
