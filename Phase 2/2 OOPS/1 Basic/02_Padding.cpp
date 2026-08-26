#include <bits/stdc++.h>
using namespace std;

/*
Padding → Compiler inserts unused bytes between members to align them
           according to architecture rules (for faster CPU access).

Packing → Forces the compiler to remove/reduce padding so the structure
          takes less memory, but may reduce performance.
*/

// Normal struct (with padding)
struct Normal
{
    char a;   // 1 byte
    int b;    // 4 bytes
    char c;   // 1 byte
};

// Another struct to observe padding
struct Check
{
    char x;
    double d;
    char m;
    int in;
};

// Packed struct (reduced/no padding)
#pragma pack(push, 1)

struct A
{
    char c;
    double i;
    char d;
};

#pragma pack(pop)   // Restores the previous packing setting

struct B
{
    char c;
    int i;
};

int main()
{
    cout << "Size of Normal struct (with padding): "
         << sizeof(Normal) << " bytes\n";

    cout << "Size of Packed struct A: "
         << sizeof(A) << " bytes\n";

    cout << "Size of struct B: "
         << sizeof(B) << " bytes\n";

    cout << "Size of Check struct: "
         << sizeof(Check) << " bytes\n";

    return 0;
}