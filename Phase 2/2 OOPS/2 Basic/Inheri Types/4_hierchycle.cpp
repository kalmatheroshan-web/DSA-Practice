#include <bits/stdc++.h>
using namespace std;

class bike
{
public:
    int silencer;
    bike()
    {
        cout << "basic controls " << endl;
    }
};

class kawasaki : public bike
{
public:
    kawasaki()
    {
        cout << "kawasaki bike is there .. " << endl;
    }
};

class yamaha : public bike
{
public:
    yamaha()
    {
        cout << "Yamaha bike is there .. " << endl;
    }
};

int main()
{

    kawasaki ninja;
    yamaha z1;

    return 0;
}