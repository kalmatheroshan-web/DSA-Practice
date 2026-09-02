/*
   ====================================================================
   COMPLETE C++ STRING & CHAR ARRAY REFERENCE (Beginner to Advanced)
   ====================================================================

   STRUCTURE:
     LEVEL 1: Basics - Char Arrays & Memory Setup
     LEVEL 2: Character Array Input & Delimiters
     LEVEL 3: C-Style String Functions (<cstring>)
     LEVEL 4: Modern C++ Strings (std::string)
     LEVEL 5: Advanced Mechanics & Common Pitfalls
     LEVEL 6: Practice Problems & Links
   ====================================================================
*/

#include <iostream>
#include <cstring>   // For C-style string functions (strlen, strcpy, etc.)
#include <string>    // For modern std::string
#include <algorithm> // For std::reverse, std::sort
using namespace std;

int main()
{
    // LEVEL 1: BASICS — CHAR ARRAYS & MEMORY LAYOUT
    // =================================================================

    // 1. Array declaration on the Stack (Mutable)
    char ch[100] = "Roshan";
    /*
       Memory Breakdown:
       - "Roshan" literal is copied into the stack array 'ch'.
       - Indices 0 to 5 : 'R', 'o', 's', 'h', 'a', 'n'
       - Index 6        : '\0' (Null Terminator - marks end of string)
       - Indices 7 to 99: Automatically zero-initialized ('\0')
    */
    cout << "Stack Array: " << ch << endl;

    // 2. String Literal Pointer (Immutable / Read-Only Memory)
    const char *p = "Roshan";
    /*
       Memory Breakdown:
       - "Roshan" resides in read-only data segment.
       - 'p' stores the address of 'R'.
       - p[0] = 'K'; // ERROR: Undefined Behavior / Segmentation Fault!
    */
    cout << "Literal Pointer: " << p << endl
         << endl;

    // LEVEL 2: INPUT HANDLING & DELIMITERS
    // =================================================================

    /*
    // A. Basic Input (cin) - Stops reading at whitespace (space, tab, newline)
    char input1[50];
    cout << "Enter a single word: ";
    cin >> input1;
    cout << "Word: " << input1 << endl;
    cin.ignore(); // Clear leftover '\n' from stream buffer

    // B. Full Line Input (cin.getline) - Reads spaces, stops at '\n' or max length
    char line[100];
    cout << "Enter a full sentence: ";
    cin.getline(line, 100); // Reads up to 99 characters + '\0'
    cout << "Line: " << line << endl;

    // C. Custom Delimiter - Reads until custom character is hit
    char textUntilDot[100];
    cout << "Enter text (stops at '.'): ";
    cin.getline(textUntilDot, 100, '.');
    cout << "Captured text: " << textUntilDot << endl;
    */

    // LEVEL 3: C-STYLE STRING FUNCTIONS (<cstring>)
    // =================================================================

    char str1[50] = "Roshan";
    char str2[] = "Kalmathe";

    // 1. strlen() — Length excluding '\0'
    cout << "Length of str1: " << strlen(str1) << endl;

    // 2. strcpy() — Copy source string to destination array
    char dest[50];
    strcpy(dest, str1);
    cout << "Copied dest: " << dest << endl;

    // 3. strcat() — Concatenate (Append)
    // IMPORTANT: Destination must have enough space to prevent overflow!
    strcat(str1, " ");
    strcat(str1, str2);
    cout << "Concatenated str1: " << str1 << endl;

    // 4. strcmp() — Lexicographical comparison
    // Returns: 0 if equal, <0 if first string is smaller, >0 if larger
    if (strcmp("Apple", "Banana") < 0)
    {
        cout << "\"Apple\" comes before \"Banana\"" << endl;
    }

    // 5. Searching: strchr (character) & strstr (substring)
    char sample[] = "Hello World";
    char *charPos = strchr(sample, 'o');    // Points to first 'o'
    char *subPos = strstr(sample, "World"); // Points to "World"

    if (charPos)
        cout << "First 'o' found at index: " << (charPos - sample) << endl;
    if (subPos)
        cout << "Substring found: " << subPos << endl;

    // 6. strtok() — String Tokenization (Modifies original string!)
    char csvData[] = "C++,Java,Python,Rust";
    cout << "Tokens:" << endl;
    char *token = strtok(csvData, ",");
    while (token != nullptr)
    {
        cout << "  - " << token << endl;
        token = strtok(nullptr, ","); // Pass nullptr to continue on same string
    }
    cout << endl;

    // LEVEL 4: MODERN C++ STRINGS (std::string)
    // =================================================================

    // 1. Dynamic allocation & safety (Auto-resizes on heap)
    string s1 = "Hello";
    string s2 = "World";
    string s3 = s1 + " " + s2; // Safe concatenation with '+'
    cout << "std::string: " << s3 << endl;
    cout << "Size: " << s3.length() << " | First char: " << s3[0] << endl;

    // 2. Input with std::string
    // string fullLine;
    // getline(cin, fullLine); // Reads full line including spaces

    // 3. Substring & Searching
    string phrase = "The quick brown fox jumps";
    string sub = phrase.substr(10, 5); // substr(startIndex, length) -> "brown"
    cout << "Extracted substring: " << sub << endl;

    size_t idx = phrase.find("fox");
    if (idx != string::npos)
    {
        cout << "'fox' found at index: " << idx << endl;
    }

    // 4. In-Place Algorithms (<algorithm>)
    reverse(s1.begin(), s1.end());
    cout << "Reversed s1: " << s1 << endl;

    // 5. Interoperability with C-APIs
    const char *c_str_version = s3.c_str(); // Returns const char*
    cout << "Converted to C-string: " << c_str_version << endl
         << endl;

    // LEVEL 5: COMMON PITFALLS TO AVOID
    // =================================================================

    /*
       PITFALL 1: Array Index Out of Bounds (Buffer Overflow)
       char small[5];
       strcpy(small, "Too Long"); // DANGER: Overwrites adjacent memory!

       PITFALL 2: Pointer Comparison vs Content Comparison
       char a[] = "Test";
       char b[] = "Test";
       if (a == b) { ... } // WRONG: Compares memory addresses, NOT content!
       if (strcmp(a, b) == 0) { ... } // CORRECT for C-strings

       PITFALL 3: Modifying String Literals
       char *str = "Hello";
       str[0] = 'h'; // CRASH: Read-only memory write!

       PITFALL 4: Safe Copy Alternative
       strncpy(dest, src, sizeof(dest) - 1);
       dest[sizeof(dest) - 1] = '\0'; // Always manual null-terminate
    */

    return 0;
}

/*
   LEVEL 6: PRACTICE PROBLEMS BY PLATFORM
   ====================================================================

   --- Easy (Core Concepts & Pointers) ---
   1. Reverse String
      - LeetCode: https://leetcode.com/problems/reverse-string/
      - GFG     : https://www.geeksforgeeks.org/problems/reverse-a-string/1

   2. Valid Palindrome
      - LeetCode: https://leetcode.com/problems/valid-palindrome/

   3. Valid Anagram
      - LeetCode: https://leetcode.com/problems/valid-anagram/
      - GFG     : https://www.geeksforgeeks.org/problems/anagram-1587115620/1

   --- Medium (Sliding Window & Tokenization) ---
   4. Longest Substring Without Repeating Characters
      - LeetCode: https://leetcode.com/problems/longest-substring-without-repeating-characters/

   5. Reverse Words in a String
      - LeetCode: https://leetcode.com/problems/reverse-words-in-a-string/

   6. Length of Last Word
      - InterviewBit: https://www.interviewbit.com/problems/length-of-last-word/

   --- Hard / String Matching Algorithms ---
   7. Implement strstr() / KMP Algorithm
      - LeetCode    : https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
      - InterviewBit: https://www.interviewbit.com/problems/implement-strstr/
*/