#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int ar[20] = {};
    cout << sizeof(ar) / sizeof(int) << endl;
    // ---------------- Create ----------------
    vector<int> v;         // Empty
    vector<int> v1(5);     // {0,0,0,0,0}
    vector<int> v2(5, 10); // {10,10,10,10,10}
    vector<int> v3 = {1, 2, 3, 4, 5};
    vector<int> copy(v3); // Copy

    // ---------------- Add ----------------
    v.push_back(10);
    v.push_back(20);
    v.emplace_back(30); // Faster

    // ---------------- Access ----------------
    cout << "Front: " << v.front() << endl;
    cout << "Back : " << v.back() << endl;
    cout << "Index 1: " << v[1] << endl;
    cout << "At(2): " << v.at(2) << endl;

    // ---------------- Traverse ----------------
    cout << "\nRange loop\n";
    for (int x : v)
        cout << x << " ";

    cout << "\nIterator\n";
    for (auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";

    // ---------------- Size ----------------
    cout << "\n\nSize: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Empty: " << v.empty() << endl;

    // ---------------- Insert ----------------
    v.insert(v.begin(), 5);      // Beginning
    v.insert(v.begin() + 2, 15); // Middle
    v.insert(v.end(), 40);       // End

    cout << "\nAfter insert:\n";
    for (int x : v)
        cout << x << " ";

    // ---------------- Erase ----------------
    v.erase(v.begin());                    // One element
    v.erase(v.begin() + 1, v.begin() + 3); // Range

    cout << "\nAfter erase:\n";
    for (int x : v)
        cout << x << " ";

    // ---------------- Pop ----------------
    v.pop_back();

    // ---------------- Resize ----------------
    v.resize(7, 100); // Fill new with 100

    cout << "\nAfter resize:\n";
    for (int x : v)
        cout << x << " ";

    // ---------------- Assign ----------------
    v.assign(4, 7); // {7,7,7,7}

    cout << "\nAfter assign:\n";
    for (int x : v)
        cout << x << " ";

    // ---------------- Clear ----------------
    v.clear();

    cout << "\nSize after clear: " << v.size() << endl;

    // ---------------- Swap ----------------
    vector<int> a = {1, 2, 3};
    vector<int> b = {10, 20};

    a.swap(b);

    cout << "\nAfter swap:\n";
    for (int x : a)
        cout << x << " ";

    // ---------------- Reserve ----------------
    vector<int> cap;
    cap.reserve(20); // Reserve memory

    cout << "\n\nReserved capacity: " << cap.capacity() << endl;

    // ---------------- Shrink ----------------
    cap.push_back(1);
    cap.push_back(2);
    cap.shrink_to_fit();

    cout << "Capacity after shrink: " << cap.capacity() << endl;

    // ---------------- Sort ----------------
    vector<int> s = {5, 1, 4, 3, 2};

    sort(s.begin(), s.end());

    cout << "\nSorted:\n";
    for (int x : s)
        cout << x << " ";

    // Descending
    sort(s.begin(), s.end(), greater<int>());

    cout << "\nDescending:\n";
    for (int x : s)
        cout << x << " ";

    // ---------------- Reverse ----------------
    reverse(s.begin(), s.end());

    cout << "\nReversed:\n";
    for (int x : s)
        cout << x << " ";

    // using array
    vector<int> arr[4];

    // 1d
    vector<int> _v(7, 12);

    // 2D vector: 10x5
    vector<vector<int>> _v1(10, vector<int>(5));

    // 2d of 10x20
    vector<vector<int>> walk(10, vector<int>(20, 0));

    // Number of  rows
    cout << "Rows = " << walk.size() << endl;

    // Number of columns
    cout << "Columns in row 0 = " << walk[0].size() << endl;

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