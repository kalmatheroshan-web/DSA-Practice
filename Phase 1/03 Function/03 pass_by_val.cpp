#include <iostream>

using namespace std;

void pass_value(int n)
{
    n++;
    cout << "fnx of n " << n << endl;
}

void pass_ref(int &n)
{
    n++;
    cout << "fnx of n " << n << endl;
}
int main()
{
    int n = 1;
    // pass_value(n);
    pass_ref(n);

    cout << "value of n " << n << endl;

    return 0;
}