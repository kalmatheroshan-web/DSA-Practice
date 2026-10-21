#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string intToRoman(int n)
    {
        string ans;
        while (n)
        {
            while (n / 1000)
            {
                ans += 'M';
                n -= 1000;
            }

            while (n / 100)
            {
                if (n / 100 == 9)
                {
                    ans += "CM";
                    n -= 900;
                }

                else if (n / 100 == 4)
                {
                    ans += "CD";
                    n -= 400;
                }

                else if (n / 500)
                {
                    ans += 'D';
                    n -= 500;
                }

                else
                {
                    ans += 'C';
                    n -= 100;
                }
            }

            while (n / 10)
            {
                if (n / 10 == 9)
                {
                    ans += "XC";
                    n -= 90;
                }
                else if (n / 10 == 4)
                {
                    ans += "XL";
                    n -= 40;
                }
                else if (n / 50)
                {
                    ans += 'L';
                    n -= 50;
                }
                else
                {
                    ans += 'X';
                    n -= 10;
                }
            }
            while (n)
            {
                if (n == 9)
                {
                    ans += "IX";
                    n -= 9;
                }
                else if (n == 4)
                {
                    ans += "IV";
                    n -= 4;
                }
                else if (n / 5)
                {
                    ans += 'V';
                    n -= 5;
                }
                else
                {
                    ans += 'I';
                    n--;
                }
            }
        }
        return ans;
    }
};

string intToRoman(int n) {
        string ans;

        // Thousands
        switch (n / 1000) {
            case 3: ans += "MMM"; break;
            case 2: ans += "MM";  break;
            case 1: ans += "M";   break;
        }
        n %= 1000;

        // Hundreds
        switch (n / 100) {
            case 9: ans += "CM"; break;
            case 8: ans += "DCCC"; break;
            case 7: ans += "DCC"; break;
            case 6: ans += "DC"; break;
            case 5: ans += "D"; break;
            case 4: ans += "CD"; break;
            case 3: ans += "CCC"; break;
            case 2: ans += "CC"; break;
            case 1: ans += "C"; break;
        }
        n %= 100;

        // Tens
        switch (n / 10) {
            case 9: ans += "XC"; break;
            case 8: ans += "LXXX"; break;
            case 7: ans += "LXX"; break;
            case 6: ans += "LX"; break;
            case 5: ans += "L"; break;
            case 4: ans += "XL"; break;
            case 3: ans += "XXX"; break;
            case 2: ans += "XX"; break;
            case 1: ans += "X"; break;
        }
        n %= 10;

        // Ones
        switch (n) {
            case 9: ans += "IX"; break;
            case 8: ans += "VIII"; break;
            case 7: ans += "VII"; break;
            case 6: ans += "VI"; break;
            case 5: ans += "V"; break;
            case 4: ans += "IV"; break;
            case 3: ans += "III"; break;
            case 2: ans += "II"; break;
            case 1: ans += "I"; break;
        }

        return ans;
    }

// c++17 destruction method
string intToRoman(int n)
{
    vector<pair<int, string>> values = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

    string ans;
    for (auto &[val, sym] : values)
    {
        while (n >= val)
        {
            ans += sym;
            n -= val;
        }
    }
    return ans;
}

int main()
{

    return 0;
}