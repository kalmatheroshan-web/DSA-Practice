#include <bits/stdc++.h>
using namespace std;
int minDist(vector<int> &ar, int x, int y)
{
    int a = -1, b = -1;
    int n = ar.size();

    for (int i = 0; i < n; i++)
    {
        if (ar[i] == x)
            a = i;
        if (ar[i] == y)
            b = i;
    }
    cout << " a = " << a << " b = " << b << endl;
    if (a == -1 && b == -1)
        return -1;

    return min(a, b);
}

int main()
{
    vector<int> ar = {1, 2, 3, 2};
    int ans = minDist(ar, 1, 2);

    cout << ans << endl;

    return 0;
}
