#include <iostream>
using namespace std;

double power_a_b(double a, int b)
{
    double ans = 1;
    int half = b >> 1;

    // O(b)*
    for (int i = 0; i < half; i++)
        ans *= a;

    ans = ans * ans;
    return (b % 2) ? ans * a : ans;
}

double power_a_b(double a, int b)
{
    long long exp = b;

    if (exp < 0)
    {
        a = 1.0 / a;
        exp = -exp; // b are now positive
    }

    double ans = 1.0;

    while (exp > 0)
    {
        if (exp & 1)
            ans *= a;

        a *= a;
        exp >>= 1;
    }

    return ans;
}

int main()
{
    double a;
    int b;

    cin >> a >> b;

    cout << "Result: " << power_a_b(a, b);

    return 0;
}
