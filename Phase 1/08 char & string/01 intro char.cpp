#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    // char array are mutable

    // char ch[100];
    // cin >> ch;

    // cout << "val " << ch << endl;
    // if (ch[5] == '\0')
    //     cout << "yes it is " << endl;
    // else
    //     cout << "everything is possible " << endl;

    // char ar[100];
    // cin.getline(ar, 10); // reads 10 char including '\0'
    // cout << "value : " << ar << endl;

    // delimiter set
    // char arr[100];

    // cout << "Enter a sentence (input stops at '.'): ";
    // cin.getline(arr, 100, '.');

    // cout << "Value: " << arr << endl;

    char ch[100] = "Roshan";
    cout << ch << endl;

    /*
        "Roshan" → This is a string literal, and it is stored in read-only memory (not in the heap).

        char ch[100] = "Roshan"; → This creates a character array of size 100 on the stack (not heap).

        The first 7 characters ('R' 'o' 's' 'h' 'a' 'n' '\0') are copied from the string literal into the array.

        The rest of the array (positions 7 to 99) are filled with '\0'.


    */

    const char *p = "Roshan";
    cout << p << endl;

    /*
    What happens here:

        - "Roshan" is created in read-only memory.

        - p is assigned the address of the first character ('R') of that literal.

        - So p "points to" the string literal.
    */

    // // strcpy() — Copy one char array to another:
    // char src[] = "World!";
    // char dest[20];
    // strcpy(dest, src);
    // cout << "src : " << src << endl;
    // cout << "dest : " << dest << endl;

    // // strcat() — Concatenate (append) strings:
    // char str1[] = "Roshan";
    // char str2[] = "Kalmathe";

    // strcat(str1, str2);
    // cout << "str1 " << str1 << endl;
    // cout << "str2 " << str2 << endl;

    // // strcmp() — Compare two char arrays
    // char str3[] = "Roshan";
    // char str4[] = "Roshan";
    // if (strcmp(str3, str4) == 0)
    // {
    //     cout << "Strings are equal" << endl;
    // }

    // // strstr returns substr pointer
    // char str5[] = "Hello World";
    // char *pos = strstr(str5, "World");
    // cout << "Substring found: " << pos << endl; // Output: World

    return 0;
}