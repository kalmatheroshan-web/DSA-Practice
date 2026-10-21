#include <bits/stdc++.h>
using namespace std;

int main()
{
    int amount = 0;
    cout << "Please enter the amount " << endl;
    cin >> amount;

    while (amount)
    {
        int current = amount / 100 ? 100 : amount / 50 ? 50
                                       : amount / 20   ? 20
                                       : amount / 10   ? 10
                                       : amount / 5    ? 5
                                       : amount / 2    ? 2
                                       : amount / 1    ? 1
                                                       : 0;

        switch (current)
        {
        case 100:
            cout << "100 Rs " << amount / 100 << endl;
            amount %= 100;
            break;

        case 50:
            cout << "50 Rs " << amount / 50 << endl;
            amount %= 50;
            break;

        case 20:
            cout << "20 Rs " << amount / 20 << endl;
            amount %= 20;
            break;

        case 10:
            cout << "10 Rs " << amount / 10 << endl;
            amount %= 10;
            break;

        case 5:
            cout << "5 Rs " << amount / 5 << endl;
            amount %= 5;
            break;

        case 2:
            cout << "2 Rs " << amount / 2 << endl;
            amount %= 2;
            break;

        case 1:
            cout << "1 Rs " << amount / 1 << endl;
            amount %= 1;
            break;

        default:
            cout << "everything is zero" << endl;
            break;
        }
    }

    return 0;
}