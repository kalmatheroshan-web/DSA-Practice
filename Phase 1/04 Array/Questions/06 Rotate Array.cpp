#include <bits/stdc++.h>
using namespace std;

void right_rotate(vector<int> &ar, int value = 1)
{
    for (int i = 0; i < value; i++)
    {
        int right = ar.back();
        int len = ar.size();
        for (int j = 1; j < ar.size(); j++)
        {
            ar[len - j] = ar[len - 1 - j];
        }
        ar[0] = right;
    }
}

/*
time : O(n * value)
space : O(1)
*/

void left_rotate(vector<int> &ar, int value = 1)
{
    for (int i = 0; i < value; i++)
    {
        int left = ar[0], len = ar.size();
        for (int i = 0; i < len - 1; i++)
            ar[i] = ar[i + 1];

        ar[len - 1] = left;
    }
}
/*
time : O(n * value)
space : O(1)
*/

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

/*
time : O(n)
space : O(1)
*/

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
