#include <bits/stdc++.h>
using namespace std;

/*
Padding → compiler inserts unused bytes between members to align them according to architecture rules (for faster CPU access).

Packing → forces compiler to remove/reduce padding so the structure takes less memory, but may reduce performance.
*/

// Normal struct (with padding)
struct Normal
{
    char a; // 1 byte
    int b;  // 4 bytes
    char c; // 1 byte
};

struct check
{
    char x;
    double d;
    char m;
    int in;
};

// Packed struct (no padding)
#pragma pack(push, 1) // force packing,

// 1-byte alignment
struct Packed
{
    char a; // 1 byte
    int b;  // 4 bytes
    char c; // 1 byte
};

int main()
{

    cout << "Size of Normal struct (with padding): " << sizeof(Normal) << " bytes\n";
    cout << "Size of Packed struct (no padding): " << sizeof(Packed) << " bytes\n";

    cout << "Size of check " << sizeof(check) << endl;

    return 0;
}