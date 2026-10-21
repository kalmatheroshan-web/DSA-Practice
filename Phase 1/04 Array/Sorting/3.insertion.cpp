#include <iostream>
using namespace std;

void insertion_asc(int ar[], int len)
{

    for (int i = 1; i < len; i++)
    {
        int j = i;
        while (j > 0)
        {
            if (ar[j] < ar[j - 1])
                swap(ar[j], ar[j - 1]);
            else
                break;
            j--;
        }
    }
}

void insertion_des(int ar[], int len)
{

    for (int i = 1; i < len; i++)
    {
        int j = i;
        while (j > 0)
        {
            if (ar[j] > ar[j - 1])
                swap(ar[j], ar[j - 1]);
            else
                break;
            j--;
        }
    }
}

void insertion_last(int ar[], int len)
{
    int i = len - 1;
    while (i >= 0)
    {
        int j = i;
        while (j < len - 1)
        {
            if (ar[j] > ar[j + 1])
                swap(ar[j], ar[j + 1]);
            else
                break;
            j++;
        }
        i--;
    }
}

// swap based
void insertionSort(int ar[] , int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = ar[i];
        int j = i - 1;

        // shift instead of swapping repeatedly
        while (j >= 0 && ar[j] > temp)
        {
            ar[j + 1] = ar[j];
            j--;
        }
        ar[j + 1] = temp;
    }
}

/*
  Time : O(N*N)
  Space : O(N)
  stable : stable
*/

int main()
{
    int ar[] = {2, 7, 8, 4, 11, 5};
    int len = sizeof(ar) / sizeof(int);

    insertion_last(ar, len);

    cout << "Printing element " << endl;
    for (int i = 0; i < len; i++)
        cout << ar[i] << " ";

    return 0;
}