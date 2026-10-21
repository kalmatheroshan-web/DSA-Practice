#include <iostream>
using namespace std;

int linear(int ar[], int size, int ele)
{

    for (int i = 0; i < size; i++)
        if (ele == ar[i])
            return i;

    return -1;
}

int main()
{

    int ar[] = {1, 2, 7, 9, 11};
    int element;
    cin >> element;
    
    int len = sizeof(ar) / sizeof(int);
    cout << len << endl;

    int index = linear(ar, len, element);
    cout << "index of element is  " << index << endl;

    // if (linear(ar, len, element))
    //     cout << "yes it is present" << endl;
    // else
    //     cout << "no it is not " << endl;

    return 0;
}