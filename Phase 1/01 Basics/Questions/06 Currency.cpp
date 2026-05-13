#include <iostream>
using namespace std;

int main()
{
    int currency;
    cout << "Enter the currency : ";

    cin >> currency;

    int _100 = 0;
    int _50 = 0;
    int _20 = 0;
    int _10 = 0;

    while (currency)
    {

        int check = (currency / 100 != 0) ? 100 : (currency / 50 != 0) ? 50
                                              : (currency / 20 != 0)   ? 20
                                              : (currency / 10 != 0)   ? 10
                                                                       : 0;
        switch (check)
        {
        case 100:
            _100 += currency / 100;
            currency = currency % 100;
            break;

        case 50:
            _50 += currency / 50;
            currency = currency % 50;
            break;

        case 20:
            _20 += currency / 20;
            currency = currency % 20;
            break;

        case 10:
            _10 += currency / 10;
            currency = currency % 10;
            break;

        default:
            cout << "Please give valid currency " << endl;
            break;
        }
    }

    cout << "100 notes " << _100 << endl;
    cout << "50 notes " << _50 << endl;
    cout << "20 notes " << _20 << endl;
    cout << "10 notes " << _10 << endl;

    return 0;
}