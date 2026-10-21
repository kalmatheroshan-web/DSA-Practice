#include <bits/stdc++.h>
using namespace std;

string check(int num, int bit)
{
    int check_bit = 1 << bit - 1;

    if (check_bit & num)
        return "bit is set";
    else
        return "not set ";
}

int xor_n(int n)
{
    if (n % 4 == 0)
        return n;
    else if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    else
        return 0;
}

int abosule(int num)
{
    int const mask = (num >> (sizeof(int) * 8 - 1));
    return (num + mask) ^ mask;
}

int main()
{
    // ****************** AND & ******************
    // ********** (1) even or odd
    // int num1 = -2;
    // cin >> num1;
    // if (num1 & 1)
    //     cout << "odd" << endl;
    // else
    //     cout << "even" << endl;

    // ************ (2) bit set or not ?
    // int num, bit;
    // cin >> num >> bit;
    // cout << "check that bit " << bit << " is set or not ?" << endl;
    // cout << "Result " << check(num, bit) << endl;

    // *********** (3) clear bit
    // int num, bit;
    // cout << "clear number's ith bit  : \n";
    // cin >> num >> bit;

    // cout << "before " << num << endl;
    // int one = 1;
    // one = one << bit-1;
    // one = ~one;
    // num = (num & one);
    // cout << "after clear " << bit << " bit " << num << endl;

    // ********** 4 reset(zero) first set bit from number
    // eg .. 11000 => 10000 , 1010=>1000
    // int num;
    // cout << "enter num for first reset a bit ";
    // cin >> num;

    // cout << "before num : " << num << endl;
    // num = num & num - 1;
    // cout << "after num : " << num;

    // ******** 5 check wheather number is power of 2 or not
    // int n;
    // cout << "check num is power of 2 or not :  ";
    // cin >> n;

    // n = n & n - 1;
    // if (n)
    //     cout << "Not power of 2" << endl;
    // else
    //     cout << "Power of 2";

    // ************* 6 number of 1'a in number
    // int n;
    // cout << "returns the number of 1's ";
    // cin >> n;
    // int count = 0;
    // //one way
    // while (n)
    // {
    //     if (n & 1 == 1)
    //     {
    //         count++;
    //     }
    //     n = n >> 1;
    // }

    // //another way
    // while (n)
    // {
    //     n= n & n-1;
    //     count++;
    // }
    // cout<<"count is : "<<count;

    // ********** OR **********

    // *************(1) set the number's ith bit :

    // cout << "set the number's ith bit : " << endl;
    // int num = 12, bit;
    // cin >> bit;
    // cout << "before num : " << num << endl;

    // bit = 1 << (bit - 1);
    // num = num | bit;

    // cout << "set the number of " << bit << "th bit" << endl;
    // cout << "after num : " << num << endl;

    // Combine Flags
    const int READ = 1 << 0;
    const int WRITE = 1 << 1;
    const int EXECUTE = 1 << 2;
    const int DELETE = 1 << 3;

    int permission = READ | WRITE;

    cout << permission << endl;
    // ********** NOT **********
    // int num = 16;
    // num = ~num; // -(n+1)
    // cout << "the number is " << num << endl;

    // ********** XOR **********
    // int num1 = 5, num2 = 12;
    // cout << (num1 ^ num2) << endl;

    // (1) toggling/filiping the last bit & returns whole num
    // int val = 0b10011;
    // cout << (1 ^ val) << endl;

    // (2) unique from pair of numbers
    // int ar[] = {2, 1, 2, 5, 7, 5, 6, 7, 6, 1, 101};
    // int len = sizeof(ar) / sizeof(int);

    // int ans = 0;
    // for (int i = 0; i < len; i++)
    //     ans ^= ar[i];

    // cout << "anser is : " << ans << endl;

    // (3) swapping
    // int a = 5, b = 7;
    // cout << "before : a -> " << a << "            b -> " << b << endl;
    // a = a ^ b;
    // b = a ^ b;
    // a = a ^ b;
    // cout << "after : a -> " << a << "            b -> " << b << endl;

    // // swapping
    // int a = 5, b = 7;
    // cout << "before : a -> " << a << "            b -> " << b << endl;
    // a = a + b;
    // b = a - b;
    // a = a - b;
    // cout << "after : a -> " << a << "            b -> " << b << endl;

    // (4) xor from (1,n)
    // int n, ans = 0;
    // cout << "enter the num ";
    // cin >> n;

    // // theta(n)
    // for (int i = 1; i <= n; i++)
    // {
    //     ans ^= i;
    // }
    // cout << ans<<endl;

    // // theta(1)
    // cout << xor_n(n);

    //  (5) xor bw (L , R)
    // int l, r;
    // int ans = 0;
    // cout << "enter the range start  , end : " << endl;
    // cin >> l >> r;
    // ans = xor_n(l - 1) ^ xor_n(r);
    // cout << "your answer is : " << ans;

    /* ceil value
       ⌈fr / n⌉ = (fr + n - 1) / n
       ⌈fr / n⌉ = (fr / n) + (fr % n != 0)
    */

    int n = 5, m = 3;

    // int val = ceil((double)n / m);
    int val = (n + m - 1) / m;

    cout << "ceil value " << val << endl;

    /*
        sum without +
        minus without -

    */

    /*
      mask creation
        0xAAAAAAAA --- 10101010...
        0x55555555 --- 01010101...

    */

    int k = 4;
    int mask = ~((1 << k) - 1); // 11110000

    mask = -1; // 11111111111111111111111111111111

    // Bits L to R Set
    int L = 2;
    int R = 5;

    mask = ((1 << (R - L + 1)) - 1) << L; // 00111100

    // Lowest Set Bit Mask
    int n = 10110000;
    mask = n & (-n); // 00010000

    int rightmostPosition(int n);

    return 0;
}

int rightmostPosition(int n)
{
    if (n & 1)
        return 1;

    if (n & (n - 1) == 0)
        return log2(n) + 1;

    return log2(n & -n) + 1;
}

// sum without + operator
int sum(int a, int b)
{
    while (b)
    {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }

    return a;
}

// subtraction without - operator
int menu(int a, int b)
{
    while (b)
    {
        int borrow = (~a) & b;
        a = a ^ b;
        b = borrow << 1;
    }

    return a;
}

/*
Bit Manipulation (C++)
ref : https://www.techiedelight.com/bit-hacks-part-5-find-absolute-value-integer-without-branching/
├── 1. Binary Basics
│   ├── Decimal ↔ Binary
│   ├── Bit Positions
│   ├── Left Shift (<<)
│   ├── Right Shift (>>)
│   └── Powers of Two
│
├── 2. AND (&)
│   ├── Check Even/Odd
│   ├── Check ith Bit
│   ├── Clear ith Bit
│   ├── Clear Last Set Bit
│   ├── Power of 2
│   ├── Power of 4
│   ├── Count Set Bits
│   ├── Extract Lowest Set Bit
│   ├── Rightmost Set Bit Position
│   └── Check Single Set Bit
│
├── 3. OR (|)
│   ├── Set ith Bit
│   ├── Set Multiple Bits
│   ├── Combine Flags
│   ├── Permission System
│   └── Turn ON Rightmost Zero Bit
│
├── 4. XOR (^)
│   ├── Toggle ith Bit
│   ├── Toggle Last Bit
│   ├── Find Unique Number
│   ├── Find Missing Number
│   ├── Swap Numbers
│   ├── XOR from 1 to N
│   ├── XOR in Range [L,R]
│   └── Check Opposite Signs
│
├── 5. NOT (~)
│   ├── Complement
│   ├── -(n+1)
│   └── Flip All Bits
│
├── 6. Shift Operators
│   ├── Multiply by 2^k
│   ├── Divide by 2^k
│   ├── Fast Multiplication
│   └── Fast Division
│
├── 7. Useful Tricks
│   ├── Print Binary
│   ├── Binary of Negative Numbers
│   ├── Absolute Value
│   ├── Ceil Division
│   ├── Sum without +
│   ├── Subtraction without -
│   ├── Binary Search Mid Overflow Trick
│   └── Mask Creation
│
├── 8. STL Built-ins
│   ├── __builtin_popcount()
│   ├── __builtin_popcountll()
│   ├── __builtin_clz()
│   ├── __builtin_ctz()
│   ├── __builtin_parity()
│   └── bitset<32>
│
├── 9. Interview Problems
│   ├── Single Number
│   ├── Two Unique Numbers
│   ├── Missing Number
│   ├── Subsets using Bits
│   ├── Gray Code
│   ├── Maximum XOR Pair
│   ├── Bitmask DP Basics
│   └── N-Queens Bitmask
│
└── 10. Complexity Summary
    ├── Check Bit → O(1)
    ├── Set Bit → O(1)
    ├── Clear Bit → O(1)
    ├── Toggle Bit → O(1)
    ├── XOR Range → O(1)
    ├── Power of 2 → O(1)
    ├── Count Bits (loop) → O(number of set bits)
    └── __builtin_popcount → O(1) (hardware optimized)
*/