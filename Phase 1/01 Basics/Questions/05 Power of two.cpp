#include <iostream>

using namespace std;

bool power_2(int num)
{
    if (num <= 0)
        return false;
    for (int i = 0; i <= 30; i++)
    {
        if (1 << i == num)
            return true;
    }

    return false;
}

bool power_two(int num)
{
    if (num <= 0)
        return false;

    return !(num & num - 1);
}

int main()
{

    int input = 15;
    if (power_2(128))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    int val = INT32_MAX;
    cout << "value " << val << endl;
    val = (1 << 31);
    cout << "value " << val << endl;

    return 0;
}