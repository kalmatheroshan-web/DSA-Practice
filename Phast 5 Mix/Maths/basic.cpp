#include <bits/stdc++.h>
using namespace std;

int func(int n) { return 1 + (n - 1) % 10; }

int main()
{
    int n = 101;
    int result = func(n);
    cout << result << endl;

    return 0;
}
