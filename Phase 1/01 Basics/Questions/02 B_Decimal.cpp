#include <bits/stdc++.h>

using namespace std;
int binary_decimal(int num)
{
    int ans = 0;
    int i = 0;
    while (num)
    {
        int last_bit = num % 10;
        ans = ans + ((1 << i) * last_bit);
        num /= 10;
        i++;
    }

    return ans;
}
int main()
{

    int number = 1100001111101;
    int binary = binary_decimal(number);
    cout << "Binary Number is " << binary << endl;

    return 0;
}