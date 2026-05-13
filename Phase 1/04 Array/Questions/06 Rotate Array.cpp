#include <iostream>
using namespace std;

void rotate(int ar[], int len)
{
    int temp = ar[len - 1];
    int i = len - 2;
    
    while (i >= 0)
    {
        ar[i + 1] = ar[i];
        i--;
    }
    ar[0] = temp;
}

int main()
{
    int ar[] = {2, 7, 8, 4, 11, 5};
    int len = sizeof(ar) / sizeof(int);

    rotate(ar, len);
    for (int i = 0; i < len; i++)
        cout << ar[i] << " ";

    return 0;
}