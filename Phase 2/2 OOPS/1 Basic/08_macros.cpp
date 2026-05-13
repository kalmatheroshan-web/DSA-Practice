#include <bits/stdc++.h>
using namespace std;

// Macro it's replace before compilation
#define PI 3.145
#define MAX(a, b) (a > b) ? a : b

float circleArea(float r) { return PI * r * r; }

float circlePerimeter(float r) { return 2 * PI * r; }

int maxi(int x, int y)
{
    return MAX(x, y);
}

int main()
{
    float r = 5;
    cout << "Area of circle = " << circleArea(r) << endl;
    cout << "Perimeter of circle = " << circlePerimeter(r) << endl;
    cout << "Max of (4,102) => " << maxi(102, 4) << endl;

    return 0;
}
