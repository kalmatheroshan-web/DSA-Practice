#include <bits/stdc++.h>
using namespace std;
/*

Given an unsorted array arr[] of size n, containing elements from the range 1 to n, it is known that one number in this range is missing, and another number occurs twice in the array, find both the duplicate number and the missing number.

    Input: arr[] = [1, 3, 3]w
    Output: [3, 2]
    Explanation: Repeating number is 3 and the missing number is 2.

    Input: arr[] = [4, 3, 6, 2, 1, 1]
    Output: [1, 5]
    Explanation: Repeating number is 1 and the missing number is 5.

*/
vector<int> findRepeatAndMissing(vector<int> &ar)
{
    int n = ar.size();

    // Step 1: Decrease all elements by 1 (convert to 0-based indexing)
    for (int i = 0; i < n; i++)
        ar[i]--;

    // Step 2: Increase count
    for (int i = 0; i < n; i++)
    {
        int inx = ar[i] % n; // get original value
        ar[inx] += n;
    }

    int missing = 0, repeat = 0;

    // Step 3: Check frequencies
    for (int i = 0; i < n; i++)
    {
        int occur = ar[i] / n;
        if (occur > 1)
            repeat = i + 1;
        else if (occur == 0)
            missing = i + 1;
    }

    return {repeat, missing};
}

int main()
{
    vector<int> ar = {4, 3, 6, 2, 1, 1};

    vector<int> ans = findRepeatAndMissing(ar);

    cout << "Repeating number: " << ans[0] << endl;
    cout << "Missing number: " << ans[1] << endl;
}