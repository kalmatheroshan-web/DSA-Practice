#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<int, 100> arr;
    arr.fill(10);
    int len = arr.size();

    // for (int i = 0; i < len; i++)
    //     cout << arr.at(i) << " ";
    // cout << endl;

    // begin() , end(), rbegin(), rend()
    array<int, 5> ar = {1, 2, 3, 4, 5};

    for (auto it = ar.begin(); it != ar.end(); it++)
    {
        cout << *it << " ";
    }

    cout << "\n\nreverse the array .. \n";

    for (auto it = ar.rbegin(); it != ar.rend(); it++)
    {
        cout << *it << " ";
    }

    cout << "\n\nsee the output" << endl;
    for (auto i = ar.end() - 1; i >= ar.begin(); i--)
    {
        cout << *i << " ";
    }

    cout << "\n\nForeach loop " << endl;
    for (auto itr : ar)
        cout << itr << " ";
    cout << endl;
    cout << endl;

    // length
    cout << "length of array " << ar.size() << endl;

    //  front
    cout << "Front ele " << ar.front() << endl;

    // back
    cout << "Back ele " << ar.back() << endl;

    return 0;
}