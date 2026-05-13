#include <bits/stdc++.h>
using namespace std;
int main()
{

  // insertion operator (<<)
  cout << "hello Roshan" << endl;

  cout << endl;
  cout << endl;

  float float_val = 32.34f;
  double double_val = 234.343;

  int i = 121.921;
  cout << "integer value " << i << endl;

  // unsigned int u_i = -231;
  unsigned u_i = 231; // unsigned int => unsigned

  // greater number
  cout << "unsigned value " << u_i << endl;

  signed int val = -12232;
  cout << "signed " << val << endl;

  int num1;
  num1 = 02567; // octal
  cout << num1 << endl;

  num1 = 077;
  cout << num1 << endl;

  num1 = 0xaa; // hexa-decimal
  cout << num1 << endl;

  num1 = 0xab;
  cout << num1 << endl;

  // binary number
  num1 = 0b10011;
  cout << num1 << endl;

  float f = 2323.34f;
  cout << "float value " << f << endl;

  bool b = true;
  cout << b << endl;
  cout << true << endl;
  cout << false << endl;

  char c = 'a';
  cout << "value " << c << endl;

  c = 'abdmefrv';
  cout << "value " << (int)c << endl;

  int ch = 'a';
  // 1701212790
  cout << "val is " << ch << endl;

  char cola = 234567;
  cout << cola << endl;

  string str = "";
  getline(cin, str); // reads the string until new line
  cout << str << endl;

  double pi = 3.14159265358979323846;
  cout << "default " << pi << endl;

  // setPrecision
  cout << setprecision(4) << pi << endl;

  // fixed setPrecision
  cout << fixed << setprecision(4) << pi << endl;

  /*
  variable
      A variable is a named container that reserves a space in memory to store
      a value that can be changed during program execution.
  */

  return 0;
}