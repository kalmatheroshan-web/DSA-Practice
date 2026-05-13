#include <bits/stdc++.h>

using namespace std;

int main()
{

    char ch;
    printf("Enter the char : ");
    // ch = getchar();  // shows character and waits for Enter
    // ch = getche();   // shows character and does NOT require Enter (echoes immediately)
    // ch = getch();    // does NOT show character and does NOT require Enter

    if (ch == 10)
    {
        printf("It is enter\n");
    }
    else if (ch == 32)
        printf("It is space\n");

    printf("The value %c", ch);

    int num;
    cin >> num;
    // check for positive
    if (num > 0)
        cout << "Number is Positive" << endl;
    else
        cout << "km chho " << endl;

    // check for positive - negative - zero
    int value;
    cin >> value;

    if (value > 0)
        cout << "Number is Positive" << endl;
    else if (value < 0)
        cout << "Number is Negative" << endl;
    else
        cout << "Number is zero" << endl;

    // diffrent way
    // if (value > 0)
    //     cout
    //         << "Number is Positive" << endl;
    // else
    // {
    //     if (value < 0)
    //         cout << "Number is Negative" << endl;
    //     else
    //         cout << "Number is zero" << endl;
    // }

    char ch;
    cin >> ch;

    if (ch >= 'a' && ch <= 'z')
        cout << "lower case" << endl;
    else if (ch >= 'A' && ch <= 'Z')
        cout << "Upper case" << endl;
    else if (ch >= '0' && ch <= '9')
        cout << "Numberic value" << endl;
    else
        cout << "Give me better Input" << endl;

    float x = 0.6f;
    double y = 0.6;

    /*
    For float (32-bit)
      [Sign bit] [Exponent: 8 bits] [Mantissa: 23 bits]
        Sign bit (S): 0 = positive, 1 = negative
        Exponent: Stored with a bias of 127
        Mantissa (Fraction): Holds the binary fractional part (with an implicit leading 1. for normalized numbers)

          0 | 01111110 | 00110011001100110011010
  */
    printf("Float  hex: 0x%08X\n", *(unsigned int *)&x);

    /*
    For double (64-bit)
      [Sign bit] [Exponent: 11 bits] [Mantissa: 52 bits]
        Exponent bias: 1023
        Same implicit leading 1. rule

          0 | 01111111110 | 0011001100110011001100110011001100110011001100110011
    */
    printf("Double hex: 0x%016llX\n", *(unsigned long long *)&y);

    if (x == .6)
        cout << "yes it is" << endl;
    else
        cout << "No it's not" << endl;

    return 0;
}