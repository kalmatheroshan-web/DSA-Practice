#include <iostream>
using namespace std;

int main()
{

    char ar[5] = "1234";
    char *ptr = ar;

    // cout treat (char *) to c-string so it prints till '\0'
    cout << ar << endl;
    cout << ptr << endl;

    char ch = 'a';
    cout << ch << endl;
    cout << &ch << endl;

    // To print Address
    cout << (void *)ar << endl;
    cout << (void *)&ch << endl;

    /*
        in vector , string

            vector<int> v;
            string s;

            v != &v[0]
            s != &s[0]

            v , s represents entire object
    */
}