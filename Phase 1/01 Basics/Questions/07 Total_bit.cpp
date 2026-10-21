#include <iostream>
using namespace std;

int total_bit(int num1, int num2)
{
    int cnt = 0;

    while (num1)
    {
        cnt++;
        num1 = num1 & num1 - 1;
    }

    while (num2)
    {
        cnt++;
        num2 = num2 & num2 - 1;
    }

    return cnt;
}

int main()
{

    cout << total_bit(15, 9) << endl;

    return 0;
}
