#include <iostream>
using namespace std;

int power_a_b(int a, int b)
{
    int ans = 1;
    int half = b >> 1;

    // O(b)
    for (int i = 0; i < half; i++)
        ans *= a;

    return (b % 2) ? ans * ans * a : ans * ans;
}

int main()
{
    int a, b;
    cin >> a >> b;

    int ans = power_a_b(a, b);
    cout << "Result " << ans;

    return 0;
}