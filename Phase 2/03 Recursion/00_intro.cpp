#include <bits/stdc++.h>
using namespace std;

void post(int days)
{
    // base condition
    if (days == 0)
    {
        cout << "Happy birthday" << endl;
        return;
    }

    // some work
    cout << days << " left for birthday" << endl;
    days--;

    // funx call
    post(days);
}

/*
    Note
        how to make tree ?
            L R Root

*/

void print_even(int n)
{
    // base condition
    if (n == 0)
        return;

    cout << n << endl;

    print_even(n - 2);
}

void print_1_n(int no)
{
    if (no == 0)
        return;

    // call fnx
    print_1_n(no - 1);

    cout << no << endl;
}

void pr_1_n(int N, int num = 1)
{
    if (num == N)
    {
        cout << N << endl;
        return;
    }

    cout << num << endl;
    pr_1_n(N, num + 1);
}

int main()
{
    post(5);

    int n = 9;
    // odd
    if (n & 1)
        n--;
    print_even(9);

    print_1_n(5);

    pr_1_n(4);

    return 0;
}