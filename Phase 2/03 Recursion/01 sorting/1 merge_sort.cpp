#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &ar, int start, int mid, int end)
{
    int len = end - start + 1;
    vector<int> temp(len);

    int i = start, j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end)
    {
        if (ar[i] <= ar[j])
            temp[k++] = ar[i++];
        else
            temp[k++] = ar[j++];
    }

    while (i <= mid)
        temp[k++] = ar[i++];

    while (j <= end)
        temp[k++] = ar[j++];

    k = 0;
    for (int st = start; st <= end; st++)
        ar[st] = temp[k++];
}

void merge2(vector<int> &ar, int start, int mid, int end)
{
    int n = mid - start + 1;
    int m = end - mid;

    int gap = (n + m) / 2 + (n + m) % 2;
    while (gap)
    {

        int left = start;
        int right = start + gap;
        while (right <= end)
        {
            if (ar[left] >= ar[right])
                swap(ar[left], ar[right]);
            left++, right++;
        }

        gap = gap == 1 ? 0 : gap / 2 + gap % 2;
    }
}

void merge_sort(vector<int> &ar, int start, int end)
{
    if (start == end)
        return;

    int mid = start + (end - start) / 2;

    // divide
    merge_sort(ar, start, mid);
    merge_sort(ar, mid + 1, end);

    // merge
    merge2(ar, start, mid, end);
}

int main()
{

    vector<int> ar = {13, 2, 1, 3, 7, 14, 5, 10};
    merge_sort(ar, 0, ar.size() - 1);

    for (int val : ar)
        cout << val << " ";

    return 0;
}