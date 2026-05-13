#include <iostream>
using namespace std;


int main()
{
    pair<int, string> p = {1, "Roshan"};

    // nested pairs
    pair<pair<string, int>, int> pt = {{"Roshan", 21}, 1};
    cout << pt.second << endl;

    pair<pair<int, int>, pair<int, int>> pr = {{20, 50}, {30, 70}};

    cout << pr.second.first << endl;

    return 0;
}