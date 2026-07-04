#include <bits/stdc++.h>
using namespace std;
/*
=====================================================
                Lambda Functions (C++11+)
=====================================================

Syntax

    [capture](parameters) -> return_type
    {
            // body
    };

Capture List
------------
    []      No capture
    [=]     Capture everything by value
    [&]     Capture everything by reference
    [x]     Capture x by value
    [&x]    Capture x by reference
    [=,&x]  All by value except x
    [&,x]   All by reference except x
    [this]  Capture current object
    [*this] Capture object by value (C++17)

Return type can usually be omitted.

    auto func = [](int a,int b){
        return a+b;
    };
*/

int main()
{

    auto hello = []()
    {
        cout << "Hello World\n";
    };
    hello();

    // with args
    auto print = [](string s)
    {
        cout << s << endl;
    };
    print("Bit Manipulation");

    // with return type
    auto sum = [](int a, int b) -> int
    {
        return a + b;
    };

    cout << "sum " << sum(10, 20) << endl;

    // Capture by Value [=]
    int a = 10;
    int b = 20;

    auto add = [=]()
    {
        return a + b;
    };

    cout << add();

    // Capture by Reference [&]
    a = 10;
    b = 20;

    auto modify = [&]()
    {
        a = 100;
        b = 200;
    };

    modify();

    cout << a << " " << b;

    // Capture Specific Variable
    a = 10;

    auto fun = [&a]()
    {
        a = 50;
    };

    fun();

    cout << a;

    // Mixed Capture
    // Everything by value except a.
    a = 10;
    b = 20;

    auto fun = [=, &a]()
    {
        a = 100;
        cout << b;
    };

    fun();

    // Everything by reference except a.
    a = 1001;
    auto fun = [&, a]()
    {
        cout << a;
    };

    // Mutable Lambda
    int x = 10;

    auto fun = [x]() mutable
    {
        x++;
        cout << x;
    };

    fun();

    cout << x;

    // iifa
    int ans = [](int a, int b)
    {
        return a + b;
    }(5, 7);

    cout << ans;

    // Lambda as Comparator (sort)
    vector<int> v = {5, 2, 8, 1, 7};

    sort(v.begin(), v.end(),
         [](int a, int b)
         {
             return a > b;
         });

    for (int x : v)
        cout << x << " ";

    // Sort Pair
    vector<pair<int, int>> vp = {
        {2, 10},
        {1, 30},
        {2, 5}};

    sort(vp.begin(), vp.end(),
         [](auto a, auto b)
         {
             if (a.first == b.first)
                 return a.second < b.second;

             return a.first < b.first;
         });
    // for each
    vector<int> v = {1, 2, 3, 4};

    for_each(v.begin(), v.end(),
             [](int x)
             {
                 cout << x << " ";
             });

    //  count ele
    vector<int> ab = {1, 2, 3, 4, 5, 6};

    int cnt = count_if(ab.begin(), ab.end(),
                       [](int x)
                       {
                           return x % 2 == 0;
                       });

    cout << cnt;

    // Lambda Returning Lambda
    auto multiply = [](int x)
    {
        return [x](int y)
        {
            return x * y;
        };
    };

    auto twice = multiply(2);

    cout << twice(10);
    return 0;
}