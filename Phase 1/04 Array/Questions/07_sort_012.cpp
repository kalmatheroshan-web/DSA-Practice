#include <bits/stdc++.h>
using namespace std;
/*

    Dutch National Flag Algorithm for sorting 0, 1, 2.
    Maintains 3 regions:
    [0 ... low-1] -> all 0s
    [low ... mid-1] -> all 1s
    [mid ... high] -> unknown
    [high+1 ... n-1] -> all 2s

    0       l-1 l     m-1 m             h h+1            n-1
   [ 0 0 0 0 0  | 1 1 1  | (0/1/2) unknown | 2 2 2 2 2 2 ]
*/

void sort_012(vector<int> &ar)
{
    int low = 0, mid = 0, high = ar.size() - 1;

    while (mid <= high)
    {
        int cur = ar[mid];
        switch (cur)
        {
        case 0:
            swap(ar[mid], ar[low]);
            mid++;
            low++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(ar[mid], ar[high]);
            high--;
            break;
        }
    }
}

int main()
{
    vector<int> ar = {0, 2, 1, 1, 2, 0, 0, 1};
    sort_012(ar);

    cout << "Sorted array: ";
    for (int x : ar)
        cout << x << " ";
    cout << endl;
}