#include <bits/stdc++.h>
using namespace std;

bool doOverlap(vector<int> l1, vector<int> r1,
               vector<int> l2, vector<int> r2)
{

    int x11 = l1[0], x12 = r1[0];
    int x21 = l2[0], x22 = r2[0];

    int y11 = r1[1], y12 = l1[1];
    int y21 = r2[1], y22 = l2[1];

    // Check whether rectangles are separated
    if (x12 < x21 || x22 < x11)
        return false;

    if (y12 < y21 || y22 < y11)
        return false;

    return true;
}

int main()
{
    vector<int> l1 = {0, 10}, r1 = {10, 0};
    vector<int> l2 = {5, 5}, r2 = {15, 0};

    if (doOverlap(l1, r1, l2, r2))
        cout << "Rectangles Overlap";
    else
        cout << "Rectangles Don't Overlap";

    return 0;
}
