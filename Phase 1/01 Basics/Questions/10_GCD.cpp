#include <bits/stdc++.h>
using namespace std;

// time O(min(a, b))
int gcd1(int a, int b) {
    int ans = 1;

    int i = 2;
    while (i <= min(a, b)) {

        if (a % i == 0 && b % i == 0) {
            ans *= i;
            a /= i;
            b /= i;
        } else
            i++;
    }

    return ans;
}

/*
Euclidean algorithm
GCD(a,b) = GCD(b, a \bmod b)
time O(log(min(a,b)))
*/
int gcd2(int a, int b) {

    while (b != 0) {
        int rem = a % b;
        a = b, b = rem;
    }

    return a;
}

// Recursive solution
int gcd(int a, int b) {
    if (!b)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) { return (a * b) / gcd(a, b); }

int main() {
    cout << gcd2(1, 23) << endl;
    return 0;
}
