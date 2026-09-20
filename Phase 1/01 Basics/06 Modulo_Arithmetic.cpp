#include <bits/stdc++.h>
using namespace std;

// Modular Addition
long long modAdd(long long a, long long b, long long m) {
    return (a % m + b % m) % m;
}

// Modular Subtraction
long long modSub(long long a, long long b, long long m) {
    return (a % m - b % m + m) % m;
}

// Modular Multiplication (Uses __int128 to prevent overflow for numbers up to 10^18)
long long modMul(long long a, long long b, long long m) {
    return (long long)((__int128)(a % m) * (b % m) % m);
}

// Extended Euclidean Algorithm to find modular inverse
long long extendedGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    long long x1, y1;
    long long gcd = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return gcd;
}

// Modular Inverse: b^(-1) % m (Works for any m if gcd(b, m) == 1)
long long modInverse(long long b, long long m) {
    long long x, y;
    if (extendedGCD(b, m, x, y) != 1) return -1; // Inverse doesn't exist
    return (x % m + m) % m;
}

// Modular Division: (a / b) % m = (a * inverse(b)) % m
long long modDiv(long long a, long long b, long long m) {
    long long inv = modInverse(b, m);
    if (inv == -1) return -1; // Division not possible
    return modMul(a, inv, m);
}

int main() {
    long long m = 1000000007;

    cout << "Addition (10 + 20) % m = " << modAdd(10, 20, m) << "\n";
    cout << "Multiplication (10^18 * 10^18) % m = " << modMul(1e18, 1e18, m) << "\n";
    cout << "Division (10 / 3) % m = " << modDiv(10, 3, m) << "\n";

    return 0;
}
