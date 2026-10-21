#include <bits/stdc++.h>
using namespace std;

class mobile
{
public:
    void keypad()
    {
        cout << "I have keypad" << endl;
    }
};

class laptop
{
public:
    void internet()
    {
        cout << "Can access the internet" << endl;
    }
};

class smartPhone : public mobile, public laptop
{
};

int main()
{
    // smartPhone vivo;
    // vivo.internet();
    // vivo.keypad();

    return 0;
}