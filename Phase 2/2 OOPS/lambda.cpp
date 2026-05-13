#include <bits/stdc++.h>
using namespace std;
/*

-- you can define function inside the function using Lambda fnx

    [capture_list](parameter_list) -> return_type {
        // function body
    }

capture list

    [ ]	captures nothing
        [x]	captures x by value

    [=]	captures all used variables by value
    
    [&]	captures all used variables by reference
        [&x]	captures x by reference

*/

int main()
{

    bool (*min)(int, int) = [](int a, int b)
    { return a < b; };

    auto max = [](int a, int b)
    { return a > b; };

    auto divide = [](double a, double b) -> double
    {
        return a / b;
    };

    cout << "Division: " << divide(10.0, 2.0) << endl;

    int x = 10, y = 20;

    auto show = [x, y]()
    {
        cout << "x: " << x << ", y: " << y << endl;
    };

    return 0;
}