#include <bits/stdc++.h>
using namespace std;

vector<int> factorial(int n)
{
    vector<int> ans = {1};
    while (n > 1)
    {
        int cr = 0;
        int len = ans.size();

        for (int i = 0; i < len; i++)
        {
            int sum = ans[i] * n + cr;
            ans[i] = sum % 10;
            cr = sum / 10;
        }

        while (cr)
        {
            ans.push_back(cr % 10);
            cr /= 10;
        }

        n--;
    }

    reverse(ans.begin(), ans.end()); // put digits in correct order
    return ans;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> res = factorial(n);

    cout << n << "! = ";
    for (int d : res)
    {
        cout << d;
    }
    cout << endl;

    return 0;
}
