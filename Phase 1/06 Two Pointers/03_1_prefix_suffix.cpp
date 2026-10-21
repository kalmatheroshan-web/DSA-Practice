#include <bits/stdc++.h>
using namespace std;

void prefix_sum(vector<int> &ar, vector<int> &pre)
{
    int n = ar.size();
    pre[0] = ar[0];

    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + ar[i];
}

void suffix_sum(vector<int> &ar, vector<int> &suf)
{
    int n = ar.size();
    suf[n - 1] = ar[n - 1];

    for (int i = n - 2; i >= 0; i--)
        suf[i] = suf[i + 1] + ar[i];
}

int main()
{
    vector<int> ar = {6, 4, 5, -3, 2, 8};
    int n = ar.size();

    vector<int> prefix(n);
    vector<int> suffix(n);

    // sum
    prefix_sum(ar, prefix);
    suffix_sum(ar, suffix);

    cout << "Prefix : ";
    for (int val : prefix)
        cout << val << " ";
    cout << endl;

    cout << "Suffix : ";
    for (int val : suffix)
        cout << val << " ";
    cout << endl;
}