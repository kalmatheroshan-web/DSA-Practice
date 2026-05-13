#include <iostream>
#include <vector>

using namespace std;

int missingNum(vector<int> &arr)
{
    int n = arr.size() + 1;
    int xorr = 0;

    int len = n - 1;

    // O(N)
    for (int i = 0; i < len; i++)
    xorr ^= arr[i] ^ i + 1;
    
    return xorr ^ n;
}

int missing_num1(vector<int> &arr)
{
    int n = arr.size() + 1;
    int sum = (1LL * n * (n + 1)) / 2;
    
    --n; 

    // O(N)
    for (int i = 0; i < n; i++)
        sum -= arr[i];

    return sum;
}

int main()
{

    return 0;
}