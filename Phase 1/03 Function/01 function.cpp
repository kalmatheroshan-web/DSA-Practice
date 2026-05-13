#include <iostream>

using namespace std;

int power(int a, int b)
{
    int ans = 1;
    while (b--)
        ans *= a;
    return ans;
}

int recursive_pow(int a, int b)
{
    if (b == 0)
        return 1;
    return a * recursive_pow(a, --b);
}

bool is_even(int num)
{
    if (num & 1)
        return 0;
    return 1;
}

int main()
{

    int num1, num2;
    cin >> num1 >> num2;

    int output = power(num1, num2);
    cout << "Output " << output << endl;

    output = is_even(11);
    cout << "the number " << (output ? "even" : "odd") << endl;

    return 0;
}