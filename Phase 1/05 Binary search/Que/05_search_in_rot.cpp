#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &ar, int ele)
{
    int len = ar.size();
    int st = 0, end = len - 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (ar[mid] == ele)
            return mid;
        // left part
        else if (ar[0] <= ar[mid])
        {
            // st to mid range
            if (ar[st] <= ele && ele <= ar[mid])
                end = mid - 1;
            else
                st = mid + 1;
        }
        // right part
        else
        {
            // mid to end range
            if (ar[mid] <= ele && ele <= ar[end])
                st = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1;
}

int main()
{

    vector<int> ar = {4, 5, 6, 7, 0, 1, 2};
    int ele = 0;

    int ans = search(ar, ele);
    cout << "ans : " << ans << endl;

    return 0;
}