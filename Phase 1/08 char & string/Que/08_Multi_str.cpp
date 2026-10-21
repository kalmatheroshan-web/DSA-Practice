#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // time : O(max(a,b))
    string add_str(string &a, string &b)
    {
        int an = a.size();
        int bn = b.size();
        int cr = 0, i = an - 1;

        string ans;

        int diff = an - bn;

        // add from reverse
        while (i >= diff)
        {
            int sum = (a[i] - '0') + (b[i - diff] - '0') + cr;
            ans += sum % 10 + '0';
            cr = sum / 10;
            i--;
        }

        // add remaining part of a
        while (i >= 0)
        {
            int sum = (a[i] - '0') + cr;
            ans += sum % 10 + '0';
            cr = sum / 10;
            i--;
        }

        // add remaining carry
        while (cr > 0)
        {
            ans += cr % 10 + '0';
            cr = cr / 10;
        }

        // reverse ans
        reverse(ans.begin(), ans.end());

        return ans;
    }

    void solve(string &ans, string &a, string &b)
    {
        int an = a.size();
        int bn = b.size();

        int i = bn - 1;
        int zero = 0;

        while (i >= 0)
        {
            int j = 0;
            string sum;

            // Adding zeros for current position
            while (j < zero) // O(min(a,b))
            {
                sum += '0';
                j++;
            }
            zero++;

            j = an - 1;
            int cr = 0; // Reset carry for each digit multiplication

            // O(a)
            // Multiply a by current digit of b
            while (cr > 0 || j >= 0)
            {
                int mul;
                if (j >= 0)
                {
                    mul = (a[j] - '0') * (b[i] - '0') + cr;
                }
                else
                {
                    mul = cr;
                }
                sum += mul % 10 + '0';
                cr = mul / 10;
                j--;
            }

            // Add remaining carry
            while (cr > 0)
            {
                sum += cr % 10 + '0';
                cr = cr / 10;
            }

            // Reverse the sum string
            reverse(sum.begin(), sum.end());

            // Add to final result
            if (ans.empty())
                ans = sum;
            else
                ans = add_str(sum, ans);

            i--;
        }
    }

public:
    // time : O(a*b)
    string multiply(string a, string b)
    {
        if (a == "0" || b == "0")
            return "0";

        string ans;
        if (a.size() >= b.size())
            solve(ans, a, b);
        else
            solve(ans, b, a);

        return ans;
    }
};

// time O(a*b) space O(a+b)
string multiply(string a, string b)
{
    if (a[0] == '0' || b[0] == '0')
        return "0";

    int an = a.size();
    int bn = b.size();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    vector<int> res(an + bn);

    for (int i = 0; i < bn; i++)
    {
        int st = i;
        int cr = 0;

        for (int j = 0; j < an; j++)
        {
            int sum = (a[j] - '0') * (b[i] - '0') + res[st] + cr;
            int rem = sum % 10;
            res[st++] = rem;
            cr = sum / 10;
        }
        if (cr)
            res[st] = cr;
    }

    int i = an + bn - 1;
    if (res[an + bn - 1] == 0)
        i--;

    string answer;

    while (i >= 0)
    {
        answer += res[i] + '0';
        i--;
    }

    return answer;
}

int main()
{
    Solution solution;

    // Test cases
    cout << "Test Case 1: 2 * 3 = " << solution.multiply("2", "3") << endl;
    cout << "Test Case 2: 123 * 456 = " << solution.multiply("123", "456") << endl;
    cout << "Test Case 3: 0 * 123 = " << solution.multiply("0", "123") << endl;
    cout << "Test Case 4: 999 * 999 = " << solution.multiply("999", "999") << endl;
    cout << "Test Case 5: 100 * 200 = " << solution.multiply("100", "200") << endl;

    return 0;
}