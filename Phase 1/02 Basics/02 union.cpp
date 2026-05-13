#include <iostream>
using namespace std;

/*
In a union, all members overlap in the same memory block.

The size of the union = size of its largest member.
*/

union hello
{
  int a, b;
  void say()
  {
    cout << "hello world" << endl;
  }
};

// nested
union its
{
  int a, b;
  union points
  {
    int x, y;
  } p;
};

int main()
{
  hello h;
  h.say();
  h.a = 100;
  cout << "value " << h.a << endl;

  its var;
  var.p.x = 10;
  var.p.y = 20;

  cout << var.p.x << endl;
  cout << var.p.y << endl;

  cout << char(42) << endl;
  return 0;
}