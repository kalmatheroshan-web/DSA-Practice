#include <bits/stdc++.h>
using namespace std;

// rotate 180deg
void rotateMatrix(vector<vector<int>> &mat)
{

    int n = mat.size();
    
    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < n; j++)
            swap(mat[i][j], mat[n - 1 - i][n - 1 - j]);

    if (n % 2 != 0)
    {
        int s = 0, e = n - 1;
        int row = n / 2;

        while (s < e)
            swap(mat[row][e--], mat[row][s++]);
    }
}

void rotate_180(vector<vector<int>> &ar){
    // row-wise reverse 

    // column-wise reverse

}

// Print in row major
void pr_row(vector<vector<int>> &ar)
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

    int row = ar.size(), col = ar[0].size();
    pr_row(ar);
    rotateMatrix(ar);
    pr_row(ar);
}