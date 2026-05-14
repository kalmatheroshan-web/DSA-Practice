#include <bits/stdc++.h>
using namespace std;

/*
    [capture](parameter)->return type{

    }

    capture
        [=] capture by value
        [*] capture by reference

    auto sum = [](int a,int b)->int{ }
*/

int main()
{
    auto sum = [](int a, int b) -> int
    {
        return a + b;
    };

    cout << "sum " << sum(10, 20) << endl;

    int a = 10, b = 20;
    auto hello = [&]() -> int
    {
        a = 24, b = 43;
        return a + b;
    };

    int result = hello();
    cout << "a " << a << " b " << b << endl;
    cout << "Result " << result << endl;

    return 0;
}