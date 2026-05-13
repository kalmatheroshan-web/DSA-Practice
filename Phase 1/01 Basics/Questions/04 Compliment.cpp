#include <bits/stdc++.h>

using namespace std;

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

int main()
{
    int input = 10;
    // int result = complement_int(input);
    int result = comp_int(input);
    cout << result << endl;

    return 0;
}