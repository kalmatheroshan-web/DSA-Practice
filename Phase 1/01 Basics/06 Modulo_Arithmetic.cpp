#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------------
// 1. Modular Addition
// --------------------------------------------------
long long modAdd(long long a, long long b, long long m)
{
    return ((a % m) + (b % m)) % m;
}

// --------------------------------------------------
// 2. Modular Subtraction
// --------------------------------------------------
long long modSub(long long a, long long b, long long m)
{
    return ((a % m) - (b % m) + m) % m;
}

// --------------------------------------------------
// 3. Modular Multiplication
// --------------------------------------------------
// __int128 prevents overflow when a and b are
// close to 10^18.
long long modMul(long long a, long long b, long long m)
{
    return (long long)((__int128)(a % m) * (b % m) % m);
}

// --------------------------------------------------
// 4. Extended Euclidean Algorithm
// --------------------------------------------------
// Finds:
//      ax + by = gcd(a, b)
//
// Returns gcd(a, b)
// and stores x and y through references.
// --------------------------------------------------
long long extendedGCD(long long a, long long b,
                      long long &x, long long &y)
{

    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    long long x1, y1;

    long long gcd = extendedGCD(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

// --------------------------------------------------
// 5. Modular Inverse
// --------------------------------------------------
// Returns b^(-1) % m
//
// Inverse exists only when:
//      gcd(b, m) == 1
// --------------------------------------------------
long long modInverse(long long b, long long m)
{

    long long x, y;

    long long gcd = extendedGCD(b, m, x, y);

    if (gcd != 1)
    {
        return -1;
    }

    // Make the answer positive
    return (x % m + m) % m;
}

// --------------------------------------------------
// 6. Modular Division
// --------------------------------------------------
// (a / b) % m
//
// This is NOT normal integer division.
//
// We calculate:
//      a * b^(-1) % m
// --------------------------------------------------
long long modDiv(long long a, long long b, long long m)
{

    long long inverse_b = modInverse(b, m);

    // Inverse doesn't exist
    if (inverse_b == -1)
    {
        return -1;
    }

    return modMul(a, inverse_b, m);
}

// --------------------------------------------------
// MAIN
// --------------------------------------------------
int main()
{

    long long m = 1000000007LL;

    cout << "Modulus = " << m << "\n\n";

    // Addition
    cout << "Addition:\n";
    cout << "(10 + 20) % m = "
         << modAdd(10, 20, m) << "\n\n";

    // Subtraction
    cout << "Subtraction:\n";
    cout << "(10 - 20) % m = "
         << modSub(10, 20, m) << "\n\n";

    // Multiplication
    cout << "Multiplication:\n";

    long long a = 1000000000000000000LL;
    long long b = 1000000000000000000LL;

    cout << "(10^18 * 10^18) % m = "
         << modMul(a, b, m) << "\n\n";

    // Modular inverse
    cout << "Modular Inverse:\n";

    cout << "Inverse of 3 = "
         << modInverse(3, m) << "\n\n";

    // Modular division
    cout << "Modular Division:\n";

    cout << "(10 / 3) % m = "
         << modDiv(10, 3, m) << "\n";

    return 0;
}
