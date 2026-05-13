#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &ar, int low, int high)
{
    int pivot = ar[high];
    int i = low - 1, j = low;

    while (j < high)
    {
        if (ar[j] <= pivot)
        {
            i++;
            swap(ar[i], ar[j]);
        }
        j++;
    }

    swap(ar[i + 1], ar[high]);
    return i;
}

void quickSort(vector<int> &ar, int low, int high)
{
    if (low >= high)
        return;

    int inx = partition(ar, low, high);

    // left
    quickSort(ar, low, inx);
    // right
    quickSort(ar, inx + 2, high);
}

int main()
{

    vector<int> ar = {2, 1, 6, 10, 4, 1, 3, 9, 7};
    quickSort(ar, 0, ar.size() - 1);

    for (int val : ar)
        cout << val << " ";

    return 0;
}