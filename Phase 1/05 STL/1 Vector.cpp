#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int ar[20] = {};
    cout << sizeof(ar) / sizeof(int) << endl;

    vector<int> vr;

    vr.push_back(1); // {1}
    vr.push_back(2); // {1 , 2}
    vr.push_back(0); // {1 , 2 , 0}
    vr.push_back(3); // {1 , 2 ,0 , 3}

    cout << vr.size() << endl;

    vr.pop_back(); // {1 , 2 , 0}
    vr.pop_back(); // {1 , 2 }
    vr.pop_back(); // {1}

    cout << vr.size() << endl;

    // clear entire vector
    vr.clear(); // {}

    vector<int> v(4); // {0 , 0 , 0 , 0 }
    cout << "size is " << v.size() << endl;
    for (auto i : v)
        cout << i << " ";

    vector<int> v2(4, 10);
    // copy vector
    // vector<int> v3(v2.begin() + 2, v2.end());
    vector<int> v3(v2);

    cout << "\nsize : " << v3.size() << endl;
    cout << "Now value is " << endl;
    for (int ele : v3)
        cout << ele << " ";
    cout << endl;

    vector<int> vull;

    vull.emplace_back(10); // fast than push_back()
    vull.emplace_back(20);
    vull.emplace_back(30);

    for (auto ele : vull)
        cout << ele << " ";
    cout << endl;

    // 2D vector
    vector<vector<int>> vec;
    vector<int> first = {1, 2};
    vector<int> second = {10, 20};
    vector<int> third = {111, 222, 333};

    vec.emplace_back(first);
    vec.emplace_back(second);
    vec.emplace_back(third);

    // printing 2d Vector
    for (auto ele : vec)
    {
        for (auto itr : ele)
        {
            cout << itr << " ";
        }
        cout << endl;
    }

    // another way

    cout << " \nanother way" << endl;

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    // 2d of 10*20
    vector<vector<int>> walk(10, vector<int>(20, 0));

    // Number of  rows
    cout << "Rows = " << walk.size() << endl;

    // Number of columns
    cout << "Columns in row 0 = " << walk[0].size() << endl;

    // using array
    vector<int> arr[4];

    // 1d
    vector<int> _v(7, 12);

    // 2D vector: 10x5
    vector<vector<int>> _v1(10, vector<int>(5));

    // 3D vector: 15x20x5
    vector<vector<vector<int>>> _v2(15, vector<vector<int>>(20, vector<int>(5)));

    // 4D vector: 12x15x20x5
    vector<vector<vector<vector<int>>>> _v3(12, vector<vector<vector<int>>>(15, vector<vector<int>>(20, vector<int>(5))));

    cout << _v3[0][0][0].size() << endl;

    vector<int> ans = {10, 20, 30, 40, 50};
    cout << "Before " << endl;
    for (int ele : ans)
        cout << ele << " ";

    ans.resize(3, 19);

    cout << endl;
    cout << "After " << endl;
    for (int ele : ans)
        cout << ele << " ";

    // size vs capacity
    vector<int> vacc;
    vacc.push_back(10);
    vacc.push_back(20);
    vacc.push_back(20);
    vacc.push_back(20);
    vacc.push_back(20);
    cout << vacc.capacity() << endl;
    cout << vacc.size() << endl;

    // insert
    vector<int> vr = {2, 3, 5};
    vr.insert(vr.begin() + 2, 10);
    for (auto ele : vr)
        cout << ele << endl;

    return 0;
}