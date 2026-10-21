#include <iostream>
#include <string>
using namespace std;

// O(n*n*n)
void sub_string1(string &s)
{
    int n = s.size();

    // start index
    for (int i = 0; i < n; i++)
    {
        // end index
        for (int j = i; j < n; j++)
        {
            // print substring from i to j
            for (int k = i; k <= j; k++)
            {
                cout << s[k];
            }
            cout << " ";
        }
        cout << endl;
    }
}

// O(n*n)
void sub_string2(string &s)
{
    int n = s.size();

    // start index
    for (int i = 0; i < n; i++)
    {
        string ans;
        // end index
        for (int j = i; j < n; j++)
        {
            ans += s[j];
            cout << ans << " ";
        }
        cout << endl;
    }
}
int main()
{
    string s = "ababc";
    int n = s.size();

    cout << "String " << endl;
    cout << s << endl;
    cout << endl;

    cout << "All substrings:\n";
    sub_string1(s);

    // sub string 2
    sub_string2(s);

    return 0;
}
