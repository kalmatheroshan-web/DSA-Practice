#include <iostream>
using namespace std;

void bubble_asc(int ar[], int len)
{

    for (int i = 0; i < len - 1; i++)
    {
        bool flag = true;
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (ar[j] > ar[j + 1])
            {
                swap(ar[j], ar[j + 1]);
                flag = false;
            }
        }
        if (flag)
            break;
    }
}

void bubble_des(int ar[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        bool flag = true;
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (ar[j] < ar[j + 1])
            {
                swap(ar[j], ar[j + 1]);
                flag = false;
            }
        }
        if (flag)
            break;
    }
}

void bubble_last(int ar[], int len)
{

    for (int i = 0; i < len - 1; i++)
    {
        bool flag = true;
        for (int j = len - 1; j > i; j--)
        {
            if (ar[j - 1] > ar[j])
            {
                swap(ar[j - 1], ar[j]);
                flag = false;
            }
        }
        if (flag)
            break;
    }
}

/*
time : O(N*N)
space : O(1)
stable : yes
*/
int main()
{
    int ar[5] = {7, 4, 2, 3, 5};
    int len = sizeof(ar) / sizeof(int);

    bubble_last(ar, len);

    cout << "Printing array " << endl;
    for (int i = 0; i < len; i++)
        cout << ar[i] << " ";

    return 0;
}