#include <bits/stdc++.h>
using namespace std;

// time O(M + N), space : O(M + N)
void mergeArrays(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();

    vector<int> ar(m + n);
    int i = 0, j = 0;
    int k = 0;

    while (i < n && j < m)
    {
        if (a[i] <= b[j])
            ar[k++] = a[i++];
        else
            ar[k++] = b[j++];
    }

    while (i < n)
    {
        ar[k++] = a[i++];
    }

    while (j < m)
    {
        ar[k++] = b[j++];
    }

    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
            a[i] = ar[i];
        else
            b[i - n] = ar[i];
    }
}

// time : (min(n,m) + nlogn + mlogm) , space : O(log n + log m)
void mergeArrays2(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();

    int i = n - 1, j = 0;

    while (i >= 0 && j < m)
    {
        if (a[i] >= b[j])
            swap(a[i--], b[j++]);
        else
            break;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

// time : O((n + m) × log(n + m)) space O(1)
void mergeArrays3(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();

    // celing value
    int gap = n + m / 2 + n + m % 2;

    while (gap)
    {
        int left = 0, right = gap;
        while (right < m + n)
        {
            if (left < n)
            {
                // ar1 ar1
                if (right < n && a[left] > a[right])
                    swap(a[left], a[right]);
                // ar1 ar2
                else if (right >= n && a[left] > b[right - n])
                    swap(a[left], b[right - n]);
            }
            else
            {
                // ar2 ar2
                if (b[left - n] > b[right - n])
                    swap(b[left - n], b[right - n]);
            }
            left++, right++;
        }

        // celing valuef
        gap = (gap > 1) ? gap / 2 + gap % 2 : 0;
    }
}

int main()
{
    vector<int> a = {2, 4, 7, 10};
    vector<int> b = {1, 2, 5, 9, 11};
    mergeArrays3(a, b);

    cout << "a values " << endl;
    for (int val : a)
        cout << val << " ";

    cout << endl;

    cout << "b values " << endl;
    for (int val : b)
        cout << val << " ";
    cout << endl;
}