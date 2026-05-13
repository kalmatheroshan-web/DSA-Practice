#include <iostream>

using namespace std;

int factorial(int n)
{
    if (n == 1 || n == 0)
        return 1;

    int ans = 1;
    for (int i = 2; i <= n; i++)
        ans *= i;

    return ans;
}

int n_c_r(int n, int r)
{
    if (r <= 0)
        return 1;

    return factorial(n) / (factorial(r) * factorial(n - r));
}

// declaration
// void print_count(int);
void print_count(int n);

int main()
{
    // declaration
    // void print_count(int );
    // void print_count(int n);

    int input = n_c_r(8, 2);
    cout << "answer is " << input << endl;

    print_count(12);

    return 0;
}

// defination
void print_count(int n)
{
    for (int i = 1; i <= n; i++)
        cout << i << " ";
    cout << endl;
}