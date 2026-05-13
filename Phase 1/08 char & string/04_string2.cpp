#include <iostream>
using namespace std;

int main()
{
    string s = "roshan";
    char ch[] = "roshan";

    s[2] = '\0';
    ch[2] = '\0';

    cout << s << endl;
    cout << ch << endl;
}
