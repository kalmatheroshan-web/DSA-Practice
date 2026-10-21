#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // ==================================================
    // Pair Creation
    // ==================================================

    pair<int, string> p1 = {1, "Roshan"};
    pair<int, string> p2(2, "Rahul");
    pair<int, string> p3 = make_pair(3, "Amit");

    // ==================================================
    // Access
    // ==================================================

    cout << "First : " << p1.first << endl;
    cout << "Second: " << p1.second << endl;

    // ==================================================
    // Modify
    // ==================================================

    p1.first = 10;
    p1.second = "Alex";

    cout << p1.first << " " << p1.second << endl;

    // ==================================================
    // Copy
    // ==================================================

    pair<int, string> copy = p1;

    cout << copy.first << " " << copy.second << endl;

    // ==================================================
    // Swap
    // ==================================================

    p1.swap(p2);

    cout << "\nAfter swap\n";
    cout << "p1: " << p1.first << " " << p1.second << endl;
    cout << "p2: " << p2.first << " " << p2.second << endl;

    // ==================================================
    // Compare
    // ==================================================

    pair<int, int> a = {1, 5};
    pair<int, int> b = {2, 3};

    cout << "\na < b : " << (a < b) << endl;
    cout << "a == b: " << (a == b) << endl;

    // ==================================================
    // Nested Pair
    // ==================================================

    pair<pair<string, int>, int> pt = {{"Roshan", 21}, 1};

    cout << "\nName : " << pt.first.first << endl;
    cout << "Age  : " << pt.first.second << endl;
    cout << "ID   : " << pt.second << endl;

    // ==================================================
    // Another Nested Pair
    // ==================================================

    pair<pair<int, int>, pair<int, int>> pr = {{20, 50}, {30, 70}};

    cout << "\n"
         << pr.first.first << endl;
    cout << pr.first.second << endl;
    cout << pr.second.first << endl;
    cout << pr.second.second << endl;

    // ==================================================
    // Pair in Vector
    // ==================================================

    vector<pair<int, string>> students;

    students.push_back({1, "A"});
    students.emplace_back(2, "B");

    cout << "\nStudents\n";
    for (auto x : students)
        cout << x.first << " " << x.second << endl;

    // ==================================================
    // Array of Pairs
    // ==================================================

    pair<int, int> arr[3] = {{1, 2}, {3, 4}, {5, 6}};

    cout << "\nArray of Pairs\n";
    for (auto x : arr)
        cout << x.first << " " << x.second << endl;

    return 0;
}