#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    // bitset<8> bit(13); // 00001101
    // bitset<8> bit("1010"); // 00001010
    bitset<8> bit; // 00000000

    // Set bits
    bit.set(0); // Read
    bit.set(1); // Write
    bit.set(3); // Execute
    cout << "After set:      " << bit << endl;

    // Set all bits
    bit.set();
    cout << "Set all:        " << bit << endl;

    // Set secific  bits
    bit.set(2);
    cout << "Set all:        " << bit << endl;

    // Reset all bits
    bit.reset();
    cout << "Reset all:      " << bit << endl;

    // Reset one bit
    bit.reset(1);
    cout << "Reset bit 1:    " << bit << endl;

    // Flip one bit
    bit.flip(2);
    cout << "Flip bit 2:     " << bit << endl;

    // Flip all bits
    bit.flip();
    cout << "Flip all:       " << bit << endl;

    // Access bit
    cout << "Bit 2:          " << bit[2] << endl;

    // Test bit
    cout << "Test bit 3:     " << bit.test(3) << endl;

    // Count set bits
    cout << "Count:          " << bit.count() << endl;

    // Size
    cout << "Size:           " << bit.size() << endl;

    // Check states
    cout << "Any:            " << bit.any() << endl;
    cout << "None:           " << bit.none() << endl;
    cout << "All:            " << bit.all() << endl;

    // Convert to integer
    cout << "To ulong:       " << bit.to_ulong() << endl;

    // Convert to string
    cout << "To string:      " << bit.to_string() << endl;

    // Create from string
    bitset<8> b1("10101010");
    cout << "From string:    " << b1 << endl;

    // Bitwise operations
    bitset<8> a("11001100");
    bitset<8> b("10101010");

    cout << "A:              " << a << endl;
    cout << "B:              " << b << endl;
    cout << "A & B:          " << (a & b) << endl;
    cout << "A | B:          " << (a | b) << endl;
    cout << "A ^ B:          " << (a ^ b) << endl;

    // Shift operations
    cout << "A << 2:         " << (a << 2) << endl;
    cout << "A >> 2:         " << (a >> 2) << endl;

    return 0;
}