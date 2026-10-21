#include <bits/stdc++.h>
using namespace std;

// A comparator is just a function that decides how to compare two values

void input(vector<vector<int>> &v)
{
    int n;
    cout << "enter the size " << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cout << "enter a and b" << endl;
        cin >> a >> b;
        v.push_back({a, b});
    }
}

void print(vector<vector<int>> &v)
{
    cout << "Here is the output " << endl;
    int n = v.size();
    for (auto vec : v)
    {
        for (int val : vec)
            cout << val << " ";
        cout << endl;
    }
}

bool comp(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];
    // return a[1] < b[1];
}

int main()
{

    vector<int> ar = {11, 2, 4, 9, 20};

    auto cust_com = [](int a, int b)
    { return a > b; };

    sort(ar.begin(), ar.end(), cust_com);
    for (int val : ar)
        cout << val << " ";
    cout << endl;

    vector<vector<int>> v;

    // input
    input(v);

    // printing
    print(v);

    // sortiing
    sort(v.begin(), v.end(), comp);

    // printing
    print(v);

    return 0;
}