#include <bits/stdc++.h>
using namespace std;

void pr(vector<vector<int>> &mat)
{
    int row = mat.size();
    // Printing
    for (auto &row : mat)
    {
        for (auto &val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

// time : O(n*n) space : O(1)
bool search_ar(vector<vector<int>> &ar, int x)
{
    int row = ar.size();
    int col = ar[0].size();

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (ar[i][j] == x)
                return 1;

    return 0;
}
// time : O( row+log(col) ) space : O(1)
bool binary_ar(vector<vector<int>> &ar, int x)
{
    int row = ar.size();
    int col = ar[0].size();

    for (int i = 0; i < row; i++)
    {
        if (ar[i][0] <= x && x <= ar[i][col - 1])
        {
            int s = 0, e = col - 1;
            while (s <= e)
            {
                int mid = s + (e - s) / 2;
                if (ar[i][mid] == x)
                    return 1;
                if (ar[i][mid] > x)
                    e--;
                else
                    s++;
            }

            return 0;
        }
    }
    return 0;
}

/*
    if 2d array if fully sorted
        {1, 2, 3, 4}
        {5, 6, 7, 8}
        {9, 10, 11, 12}
        {13, 14, 15, 16}

*/
// time : O( log(row*col) ) space : O(1)
bool search_sorted(vector<vector<int>> &ar, int x)
{
    int row = ar.size();
    int col = ar[0].size();
    int s = 0, e = row * col - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        int ri = mid / col, ci = mid % col;

        if (ar[ri][ci] == x)
            return 1;
        if (ar[ri][ci] > x)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return 0;
}
int main()
{

    vector<vector<int>> a = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    pr(a);
    cout << "6 is present " << search_ar(a, 6) << endl;
}