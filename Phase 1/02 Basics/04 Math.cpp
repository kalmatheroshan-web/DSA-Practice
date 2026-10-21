#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x = 25.0, y = 3.0, angle = 45.0;

    // Square root
    cout << "sqrt(" << x << ") = " << sqrt(x) << endl;

    // Power
    cout << "pow(2, 3) = " << pow(2, 3) << endl;

    // Absolute value |-a| = a
    cout << "abs(-10) = " << abs(-10) << endl;

    // Ceiling (round up)
    cout << "ceil(4.2) = " << ceil(4.2) << endl;

    // Floor (round down)
    cout << "floor(4.8) = " << floor(4.8) << endl;

    // Rounding to the nearest integer
    cout << "round(4.5) = " << round(4.5) << endl;

    // Trigonometric functions (convert degrees to radians)
    double radians = angle * M_PI / 180.0;
    cout << "sin(45 degrees) = " << sin(radians) << endl;
    cout << "cos(45 degrees) = " << cos(radians) << endl;
    cout << "tan(45 degrees) = " << tan(radians) << endl;

    // Exponential function (e^x)
    cout << "exp(2) = " << exp(2) << endl;

    // Natural logarithm (base e)
    cout << "log(" << x << ") = " << log(x) << endl;

    // Logarithm base 10
    cout << "log10(" << x << ") = " << log10(x) << endl;

    // min max from two number
    cout << max(10, 30) << endl;
    cout << min(10, 30) << endl;

    return 0;
}
