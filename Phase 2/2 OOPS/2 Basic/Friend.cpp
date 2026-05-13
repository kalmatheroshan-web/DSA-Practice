#include <bits/stdc++.h>
using namespace std;

class a
{
    int sum;

public:
    a() { this->sum = 0; }
    a(int a) { this->sum = a; }
    void print()
    {
        cout << "sum " << sum << endl;
    }

    friend int main();
    friend class thopo;
};
class thopo
{
public:
    void say()
    {
        a drama(110);
        cout << drama.sum << endl;
    }
};
int main()
{

    a obj(200);
    
    obj.print();
    cout << obj.sum << endl;
    
    thopo bang;
    bang.say();

    return 0;
}