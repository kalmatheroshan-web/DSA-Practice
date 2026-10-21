#include <bits/stdc++.h>
using namespace std;
/*
Given an array, print all possible subarrays.

Example:
[4, 3, 7]

Subarrays:
[4] [3] [7] [4,3] [3,7] [4,3,7]

*/

/*
Time: O(N³)
Extra space: O(1)
*/

void subArray(vector<int> &ar)
{
    int n = ar.size();

    for (int i = 0; i < n; i++) // start
    {
        for (int j = i; j < n; j++) // end
        {
            cout << "[";
            for (int k = i; k <= j; k++) // print
            {
                cout << ar[k] << " ";
            }
            cout << "]\n";
        }
    }
}


int main()
{
    vector<int> ar = {4, 3, 7, 2, 10, 8};
    subArray(ar);
}
