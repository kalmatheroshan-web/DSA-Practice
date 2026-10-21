#include <iostream>
#include <stack>

using namespace std;

int main()
{
    // ===== Create =====
    stack<int> s;       // Empty stack
    stack<int> copy(s); // Copy stack

    // ===== Push =====
    s.push(10); // Insert element
    s.push(20);
    s.emplace(30); // Construct in-place

    // ===== Access =====
    cout << "Top: " << s.top() << endl;

    // ===== Size =====
    cout << "Size: " << s.size() << endl;
    cout << "Empty: " << s.empty() << endl;

    // ===== Pop =====
    s.pop(); // Remove top

    cout << "Top after pop: " << s.top() << endl;

    // ===== Swap =====
    stack<int> s2;

    s2.push(100);
    s2.push(200);

    s.swap(s2); // Swap contents

    cout << "\nAfter swap\n";
    cout << "Top of s : " << s.top() << endl;
    cout << "Top of s2: " << s2.top() << endl;

    // ===== Traverse =====
    // Stack has NO iterators.
    // Copy and pop to print elements.

    stack<int> temp = s;

    cout << "\nStack elements: ";
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // ===== Clear =====
    while (!s.empty())
        s.pop();

    cout << "\nSize after clear: " << s.size() << endl;
    cout << "Empty: " << s.empty() << endl;

    // ===== Different Data Types =====

    stack<char> st1;
    stack<string> st2;
    stack<pair<int, int>> st3;

    st3.push({1, 2});

    cout << "\nPair top: "
         << st3.top().first << " "
         << st3.top().second << endl;

    // ===== LIFO Example =====

    stack<int> ex;

    for (int i = 1; i <= 5; i++)
        ex.push(i);

    cout << "\nLIFO Order: ";

    while (!ex.empty())
    {
        cout << ex.top() << " ";
        ex.pop();
    }

    return 0;
}