#include <iostream>
using namespace std;

void reverse(int ar[], int size)
{
    int start = 0, end = size - 1;
    while (start <= end)
        swap(ar[start++], ar[end--]);
}

int main()
{

    int ar[] = {2, 7, 9, 10, 12, 19};
    int len = sizeof(ar) / sizeof(int);

    cout << "before : ";

    for (int i = 0; i < len; i++)
        cout << ar[i] << " ";

    reverse(ar, len);

    cout << endl
         << "after : ";
    for (int i = 0; i < len; i++)
        cout << ar[i] << " ";

    return 0;
}