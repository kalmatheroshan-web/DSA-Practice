#include <bits/stdc++.h>

using namespace std;

/*
    10 in binary = 1010
    Complement    = 0101
*/

int complement_int(int num)
{
    int ans = 0;
    int i = 0;
    while (num)
    {
        int com_bit = (num ^ 1) & 1;
        ans = ans + (1 << i++) * com_bit;
        num = num >> 1;
    }

    return ans;
}

int comp_int(int num)
{
    if (num == 0)
        return 1;

    // mask
    int dummy = num;
    int mask = 0;
    while (dummy)
    {
        mask = (mask << 1) | 1;
        dummy >>= 1;
    }

    int ans = ~num & mask;
    return ans;
}

int findComplement(int num)
{

    if (num == 0 || num == 1)
        return !num;

    int ans = 0, i = 0;
    while (num)
    {
        int bit = num & 1;

        if (bit == 0)
            ans = ans | (1 << i);
        i++;
        num >>= 1;
    }
    return ans;
}

int main()
{
    int input = 10;
    // int result = complement_int(input);
    int result = comp_int(input);
    cout << result << endl;

    return 0;
}