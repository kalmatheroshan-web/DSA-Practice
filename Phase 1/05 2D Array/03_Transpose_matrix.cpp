#include <bits/stdc++.h>
using namespace std;
// time : O(n*n) space : O(n*n)
void Transpose(vector<vector<int>> &ar, vector<vector<int>> &res)
{
    int row = res.size();
    int col = res[0].size();

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            res[i][j] = ar[j][i];
}

// time : O(n*n)  space : O(1)
void transpose(vector<vector<int>> &ar)
{
    int row = ar.size();
    int col = ar[0].size();

    for (int i = 0; i < row - 1; i++)
        for (int j = i + 1; j < col; j++)
            swap(ar[i][j], ar[j][i]);
}

// Print in row major
void pr_row(vector<vector<int>> ar)
{
    cout << "\nRow Major" << endl;
    int row = ar.size();
    int col = ar[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << ar[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> ar = {{1, 2, 3, 4},
                              {5, 6, 7, 8},
                              {9, 10, 11, 12},
                              {13, 14, 15, 16}};

    int row = ar.size();
    int col = ar[0].size();
    // vector<vector<int>> ans(col, vector<int>(row, 0));

    // Transpose(ar, ans);
    // pr_row(ar);
    // pr_row(ans);

    pr_row(ar);
    transpose(ar);
    pr_row(ar);
}