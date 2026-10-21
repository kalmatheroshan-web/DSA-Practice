#include <bits/stdc++.h>
using namespace std;

void print(int bit, string &ans, vector<string> &res)
{
    if (bit == 0)
    {
        res.push_back(ans);
        return;
    }

    // adding the 0
    ans.push_back('0');
    print(bit - 1, ans, res);

    ans.pop_back();

    // adding the 1
    ans.push_back('1');
    print(bit - 1, ans, res);

    ans.pop_back();
}


int main()
{
    string ans;
    vector<string> res;
    print(3, ans, res);

    for (string val : res)
        cout << val << endl;

    return 0;
}