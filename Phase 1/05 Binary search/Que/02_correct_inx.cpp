#include <iostream>
using namespace std;

int correct_index(int ar[], int len, int ele)
{
    int start = 0, end = len - 1;
    int ans = -1;
    while (start <= end)
    {
        int mid = end + (start - end) / 2;
        if (ar[mid] > ele)
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return ans;
}

int main()
{

    int ar[] = {1, 4, 6, 8, 10, 14, 16, 18};
    int len = sizeof(ar) / sizeof(int);
    int ele = 5;

    int result = correct_index(ar, len, ele);
    cout << "ele correct index : " << result << endl;

    return 0;
}