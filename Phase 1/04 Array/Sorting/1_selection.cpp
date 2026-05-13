#include <iostream>
using namespace std;

void selection_asc(int ar[], int len)
{
    for (int cur = 0; cur < len - 1; cur++)
    {
        // find minimum
        int min_index = cur;
        for (int j = cur + 1; j < len; j++)
        {
            if (ar[j] < ar[min_index])
                min_index = j;
        }

        // swap with cur index
        swap(ar[cur], ar[min_index]);
    }
}

void selection_des(int ar[], int len)
{
    for (int cur = 0; cur < len - 1; cur++)
    {
        // find maximum
        int max_index = cur;
        for (int j = cur; j < len; j++)
        {
            if (ar[j] > ar[max_index])
                max_index = j;
        }

        // swap with cur index
        swap(ar[cur], ar[max_index]);
    }
}
/*
  Time : O(N*N)
  Space : O(1)
  stable : Not stable   eg (4,a)  (2,x)  (4,b)  (3,y)
*/

void stable_selection(int ar[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        // finding minimum index
        int mini_index = i;
        for (int j = i + 1; j < len; j++)
        {
            if (ar[j] < ar[mini_index])
            {
                mini_index = j;
            }
        }

        // shifting till min_index
        int key = ar[mini_index];

        while (mini_index > i)
        {
            ar[mini_index] = ar[mini_index - 1];
            mini_index--;
        }
        ar[i] = key;
    }
}

int main()
{
    int ar[] = {2, 7, 8, 4, 11, 1};
    int len = sizeof(ar) / sizeof(int);

    stable_selection(ar, len);
    cout << "Printing element " << endl;
    for (int i = 0; i < len; i++)
        cout << ar[i] << " ";

    return 0;
}