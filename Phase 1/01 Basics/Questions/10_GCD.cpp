#include <bits/stdc++.h>
using namespace std;

// time O(min(a, b))
int gcd1(int a, int b)
{
    // code here
    int ans = 1;

    int i = 2;
    while (i <= min(a, b))
    {

        if (a % i == 0 && b % i == 0)
        {
            ans *= i;
            a /= i;
            b /= i;
        }
        else
            i++;
    }

    return ans;
}

// Euclidean algorithm time O(log(min(a,b)))
int gcd2(int a, int b)
{

    while (a && b)
    {
        if (a >= b)
            a = a % b;
        else
            b = b % a;
    }

    if (a == 0)
        return b;
    return a;
}

int main()
{

    cout << gcd2(1, 23) << endl;

    return 0;
}