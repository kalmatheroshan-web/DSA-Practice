#include <iostream>

using namespace std;

int main()
{

    // ************ scope ************
    // block scope
    int value = 101;
    {
        int value = 302;
        {
            int value = 403;
            cout << value << endl; // local variable first
        }
        cout << value << endl;
    }

    cout << "value " << value << endl;

    int i = 8;
    for (int i = 0; i < 18; i++)
    {
        cout << "Hi " << i << endl;
    }
    cout << "value  of i " << i << endl;

    // cout << 2 + 3 * 5 << endl;

    // int init = -8;
    // cout << "value is " << (12 * 12 / 6 % 2) << endl;

    // int x = 3 + 3 * 4 * 3 / 6 / 4 * 3 - 2;
    // cout << "val x " << x << endl;

    // cout << (int)5.0 / 2 << endl;

    return 0;
}