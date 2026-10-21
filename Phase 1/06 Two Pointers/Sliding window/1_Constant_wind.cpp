#include <bits/stdc++.h>
using namespace std;

int max_sum(vector<int> ar, int window_size)
{
    int maxi_sum = 0;
    int n = ar.size();

    for (int i = 0; i < window_size; i++)
        maxi_sum += ar[i];

    int sum = maxi_sum;

    int left = 0, right = window_size - 1;
    while (right < n - 1)
    {
        sum -= ar[left];
        left++;
        right++;
        sum += ar[right];

        maxi_sum = max(maxi_sum, sum);
    }

    return maxi_sum;
}

/*
    time : O(n+k)
    space : O(1)
*/

int main()
{
    vector<int> ar = {-1, 2, 3, 4, 5, -2};
    int k = 4;

    int value = max_sum(ar, k);

    cout << "maximum " << value << endl;

    return 0;
}
