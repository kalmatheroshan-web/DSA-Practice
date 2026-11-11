#include <bits/stdc++.h>
using namespace std;
/*
time : O(n * value)
space : O(1)
*/
void right_rotate(vector<int> &ar, int value = 1)
{
    int n = ar.size();
    value = value % n;
    for (int i = 0; i < value; i++)
    {
        int right = ar.back();
        for (int j = 1; j < n; j++)
            ar[n - j] = ar[n - 1 - j];
        ar[0] = right;
    }
}

/*
time : O(n * value)
space : O(1)
*/
void left_rotate(vector<int> &ar, int value = 1)
{

    int n = ar.size();
    value = value % n;

    for (int i = 0; i < value; i++)
    {
        int left = ar[0];
        for (int i = 0; i < n - 1; i++)
            ar[i] = ar[i + 1];

        ar[n - 1] = left;
    }
}

/*
time : O(n)
space : O(1)
*/
// left
void rotateArr(vector<int> &ar, int d)
{
    int n = ar.size();
    if (n == 0 || n == 1)
        return;

    d %= n;
    reverse(ar.begin(), ar.begin() + d);
    reverse(ar.begin() + d, ar.end());
    reverse(ar.begin(), ar.end());
}

int main()
{
    vector<int> ar = {2, 7, 8, 4, 11, 5};
    for (int val : ar)
        cout << val << " ";
    cout << endl;

    rotateArr(ar, 2);
    for (int val : ar)
        cout << val << " ";

    right_rotate(ar, 2);
    for (int val : ar)
        cout << val << " ";

    return 0;
}
