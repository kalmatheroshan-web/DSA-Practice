#include <iostream>
using namespace std;
/*
  it used to assign int constant to name
  size of enum = int
*/
// enum weeks {Sun, Mon, Tue, Wed, Thu, Fri, Sat};
enum weeks
{
    Sun = 1,
    Mon,
    Tue,
    Wed,
    Thu,
    Fri,
    Sat
};

int main()
{

    weeks day = Fri; // 6
    cout << day << endl;

    // ---- extra ----

    using i = int;
    typedef int in;
    in vac = 12313;
    cout << "value vac " << vac << endl;
    i a = 10;
    int val = 200;
    cout << "value val " << val << endl; // 200
    cout << "value a " << a << endl;

    return 0;
}