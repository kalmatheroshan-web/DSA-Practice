#include <bits/stdc++.h>
using namespace std;

bool target_sum(vector<int> &ar, int tar, int inx = 0)
{
    if (tar == 0)
        return 1;

    if (inx == ar.size() || tar < 0)
        return 0;

    // take it
    bool one = target_sum(ar, tar - ar[inx], inx + 1);

    // not take it
    bool sec = target_sum(ar, tar, inx + 1);

    return one || sec;
}

int main()
{
    vector<int> ar = {3, 4, 5};
    int tar = 7;

    if (target_sum(ar, tar))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}