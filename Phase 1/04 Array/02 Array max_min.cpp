#include <iostream>

using namespace std;

int getMax(int ar[], int size)
{
    int max = INT32_MIN;
    for (int i = 0; i < size; i++)
        if (max < ar[i])
            max = ar[i];

    return max;
}

int getMin(int ar[], int size)
{
    int min = INT32_MAX;
    for (int i = 0; i < size; i++)
        if (ar[i] < min)
            min = ar[i];
    return min;
}

int main()
{

    int size;
    cin >> size;

    // bad idea
    // int ar[size];

    // better Practice
    int ar[100];

    for (int i = 0; i < size; i++)
    {
        cin >> ar[i];
    }

    int maxi = getMax(ar, size);
    cout << "Maximum of given array is " << maxi << endl;

    int mini = getMin(ar, size);
    cout << "Minimum of given array is " << mini << endl;

    cout << max(90, 10) << endl;

    cout << min(20, 10) << endl;

    return 0;
}