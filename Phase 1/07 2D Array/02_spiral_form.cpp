#include <bits/stdc++.h>
using namespace std;

// O(n*n)
void spiral_print(vector<vector<int>> ar)
{
    int row = ar.size();
    int col = ar[0].size();

    int ri = 0;
    int ci = 0;

    while (row != ri && col != ci)
    {
        // Top
        for (int i = ci; i < col; i++)
            cout << ar[ri][i] << " ";
        cout << endl;
        ri++;

        // Right
        for (int i = ri; i < row; i++)
            cout << ar[i][col - 1] << " ";
        cout << endl;
        col--;

        // Bottom
        for (int i = col - 1; i >= ci; i--)
            cout << ar[row - 1][i] << " ";
        cout << endl;
        row--;

        // left
        for (int i = row - 1; i >= ri; i--)
            cout << ar[i][ci] << " ";
        cout << endl;

        ci++;
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> ar = {{1, 2, 3, 4, 5, 6},
                              {7, 8, 9, 10, 11, 12},
                              {13, 14, 15, 16, 17, 18},
                              {19, 20, 21, 22, 23, 24},
                              {25, 26, 27, 28, 29, 30},
                              {31, 32, 33, 34, 35, 36}};
    spiral_print(ar);
}