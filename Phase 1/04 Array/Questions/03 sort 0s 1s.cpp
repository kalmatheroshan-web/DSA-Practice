#include <iostream>
using namespace std;

void sortZeroesAndOne(int input[], int size)
{
    int st = 0, end = size - 1;
    // O(n)
    while (st < end)
    {
        if (input[st] == 0)
            st++;
        if (input[end] == 1)
            end--;
        else
            swap(input[st], input[end]);
    }
}

int main()
{
    int arr[] = {0, 1, 1, 0, 1, 0, 1};

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << endl;

    cout << "Before" << endl;
    for (auto ele : arr)

        cout << ele << " ";

    sortZeroesAndOne(arr, n);

    cout << endl;
    cout << "After" << endl;
    for (auto ele : arr)
        cout << ele << " ";

    int array[] = {1, 0, 1, 1, 0, 1, 0, 1};
    n = sizeof(array) / sizeof(array[0]);

    cout << endl;
    cout << "Before" << endl;
    for (auto ele : array)
        cout << ele << " ";

    sortZeroesAndOne(array, n);

    cout << endl;
    cout << "After" << endl;
    for (auto ele : array)
        cout << ele << " ";

    return 0;
}
