#include <iostream>

using namespace std;
void printing(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    // declaring
    int number[15];

    // accessing the val at 12
    // cout << number[12] << endl;

    // garbage value
    // cout << number[20] << endl;

    // length calculation
    // int first[] = {10, 20, 30, 40, 60};
    // int len = sizeof(first) / sizeof(int);
    // cout << len << endl;

    // ar initialization all by 0
    // int ar[100] = {};
    // int ar[20];
    // ar[10] = 12;
    // cout << "first " << ar[1] << endl;
    // cout << "second " << ar[10] << endl;

    // cout << ar[99] << endl;

    //  arr initialization all by 12
    // int arr[10];
    // fill(begin(arr), end(arr), 12);

    // int len = sizeof(arr) / sizeof(int);

    /*

        int arr[5] = {10 , 20, 30 , 40 , 50};

        address(arr) = base + { index - baseIndex } * size of data type
        baseIndex = here is 0. it can be anything

    */

    char ch[4] = {'a', 'b', 'c', 'd'};

    for (int i = 0; i < 4; i++)
        cout << ch[i] << " ";

    cout << "Printing done .. " << endl;

    return 0;
}