#include <bits/stdc++.h>
using namespace std;
/*
    array always stored in contiguous location

*/

// Print in row major
void pr_row(int ar[][3], int row, int col)
{
    cout << "\nRow Major" << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << ar[i][j] << " ";
        cout << endl;
    }
}
// Print in row major
void pr_row(int ar[][4], int row, int col)
{
    cout << "\nRow Major" << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << ar[i][j] << " ";
        cout << endl;
    }
}

// Print in col major
void pr_col(int ar[][3], int row, int col)
{
    cout << "\nColumn Major" << endl;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
            cout << ar[j][i] << " ";
        cout << endl;
    }
}

// Search in array
bool search_ar(int ar[][3], int ele, int row, int col)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (ar[i][j] == ele)
                return true;
    return false;
}

// Add two matrix
void add_two(int ar[][3], int br[][3], int res[][3], int row, int col)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            res[i][j] = ar[i][j] + br[i][j];
}

// Print row index with max sum
int max_row_sum(int ar[][4], int row, int col)
{
    int maxi_sum = INT32_MIN, index = -1;
    for (int i = 0; i < row; i++)
    {
        int total = 0;
        for (int j = 0; j < col; j++)
            total += ar[i][j];

        if (total > maxi_sum)
        {
            maxi_sum = total;
            index = i;
        }
    }
    return index;
}

// Diagonal sum
void diagonal_sum(int ar[][4], int row, int col)
{

    int i = 0;
    int sum = 0, sec_sum = 0;
    while (i < row)
    {
        sum += ar[i][i];
        sec_sum += ar[i][col - i - 1];
        i++;
    }
    cout << "first " << sum << endl
         << "second " << sec_sum << endl;
}

// Reverse each row
void reverse_row(int ar[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int s = 0, e = col - 1;
        while (s < e)
        {
            swap(ar[i][s++], ar[i][e--]);
        }
    }
}
int main()
{
    int ar[4][3] = {{1, 2, 3}, {10, 20, 30}, {100, 200, 300}, {1000, 2000, 3000}};
    cout << "row : " << sizeof(ar) / sizeof(ar[0]) << endl;
    cout << "col : " << sizeof(ar[0]) / sizeof(int) << endl;

    int row = sizeof(ar) / sizeof(ar[0]);
    int col = sizeof(ar[0]) / 4;

    pr_row(ar, row, col);
    pr_col(ar, row, col);

    int tar = 1000;
    if (search_ar(ar, tar, row, col))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    int a[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int b[][3] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120};

    int result[][3] = {};
    add_two(a, b, result, row, col);

    pr_row(result, 4, 3);

    int max_sum[][4] = {3, 4, 7, 18, 2, 8, 3, 9, 5, 4, 2, 2, 7, 3, 0, 8, 2, 8, 9, 101};
    int answer = max_row_sum(max_sum, 5, 4);
    cout << "max index with row " << answer << endl
         << endl;

    int arr[4][4] = {5, 8, 3, 9, 6, 2, 8, 4, 5, 3, 2, 2, 2, 8, 1, 9};
    diagonal_sum(arr, 4, 4);

    int rev[][4] = {2, 3, 4, 5, 1, 2, 6, 8, 4, 9, 3, 2};
    reverse_row(rev, 3, 4);
    pr_row(rev, 3, 4);
}