#include <iostream>
using namespace std;

int binary_search(int ar[], int len, int ele)
{
    int start = 0;
    int end = len - 1;
    while (start <= end)
    {
        int mid = end + (start - end) / 2;

        if (ar[mid] == ele)
            return mid;
        else if (ele > ar[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int binary_search_des(int ar[], int len, int ele)
{
    int start = 0, end = len - 1;
    while (start <= end)
    {
        int mid = end + (start - end) / 2;

        if (ar[mid] == ele)
            return mid;
        else if (ar[mid] < ele)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int main()
{
    int ar[] = {20, 40, 70, 80, 110};
    // int ar[] = {110, 80, 70, 40, 20};
    int len = sizeof(ar) / sizeof(int);

    cout << "Printing element " << endl;
    for (int i = 0; i < len; i++)
        cout << ar[i] << " ";

    cout << endl;

    int ele = 80;
    int inx = binary_search(ar, len, ele);
    cout << "ele found at " << inx << endl;

    return 0;
}
