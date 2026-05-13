#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "top element " << s.top() << endl;
    s.pop();
    cout << "stack top element " << s.top() << endl;
    cout << "size of stack" << s.size() << endl;
    cout << "is empty  " << s.empty() << endl;

    // swap
    stack<int> s2;
    s2.push(100);

    cout << "After swap, top of s: " << s.top() << endl;
    cout << "After swap, top of s2: " << s2.top() << endl;

    return 0;
}