#include <iostream>

using namespace std;

int Product_sum(int num)
{
    int product = 1, sum = 0;

    // iterate over digits
    while (num)
    {
        int last_dg = num % 10;
        sum += last_dg;
        product *= last_dg;
        num /= 10;
    }
    cout << "product " << product << endl;
    cout << "sum " << sum << endl;

    return product - sum;
}

int main()
{

    int input = 4421;
    int ans = Product_sum(input);
    cout << "answer is " << ans << endl;

    return 0;
}