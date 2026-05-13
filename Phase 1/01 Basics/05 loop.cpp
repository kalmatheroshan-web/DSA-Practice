#include <iostream>
using namespace std;

int main()
{

        // *********** while ***********
        /*
                Syntaxt

                while(condition){

                }
        */

        // even sum of n
        int num, sum = 0;
        cin >> num;

        int i = 2;
        while (i <= num)
        {
                sum += i;
                i += 2;
        }
        cout << "final sum is " << sum << endl;

        // is Prime or not
        bool is_prime = 1;
        int number = 11, cnt = 0;

        i = 2;
        while (i < number)
        {
                if (!(number % i))
                {
                        cnt++;
                        if (cnt > 0)
                        {
                                is_prime = 0;
                                break;
                        }
                }
                i++;
        }

        if (is_prime)
                cout << "It's Prime number" << endl;
        else
                cout << "It's not a  prime number" << endl;

        // *********** Patterns ***********
        /* (1)
                1 1 1 1
                2 2 2 2
                3 3 3 3
                4 4 4 4
        */
        number = 4;
        int row = 1;
        // cout << "Patterns " << endl;
        // while (row <= number)
        // {
        //     int col = 1;
        //     while (col <= number)
        //     {
        //         cout << row << " ";
        //         col++;
        //     }
        //     cout << endl;

        //     row++;
        // }

        /* (2)
                4 3 2 1
                4 3 2 1
                4 3 2 1
                4 3 2 1
        */

        // number = 4;
        // row = 1;
        // while (row <= number)
        // {
        //     int col = number;
        //     while (col >= 1)
        //     {
        //         cout << col << " ";
        //         col--;
        //     }
        //     cout << endl;

        //     row++;
        // }

        /* (3)
                1 2 3 4
                1 2 3 4
                1 2 3 4
                1 2 3 4
        */
        // number = 4;
        // row = 1;
        // while (row <= number)
        // {
        //     int col = 1;
        //     while (col <= number)
        //     {
        //         cout << col << " ";
        //         col++;
        //     }

        //     cout << endl;
        //     row++;
        // }

        /* (4)
                1 2 3
                4 5 6
                7 8 9
        */
        // number = 3;
        // row = 1;
        // cnt = 1;
        // while (row <= number)
        // {
        //     int col = 1;
        //     while (col <= number)
        //     {
        //         cout << cnt++ << " ";
        //         col++;
        //     }
        //     cout << endl;
        //     row++;
        // }

        /* (5)
         *
         * *
         * * *
         * * * *
         */
        // number = 4;
        // row = 1;
        // while (row <= number)
        // {
        //     int col = 1;
        //     while (col <= row)
        //     {
        //         cout << "*" << " ";
        //         col++;
        //     }
        //     cout << endl;
        //     row++;
        // }

        /* (6)
                1
                2 2
                3 3 3
                4 4 4 4
         */
        // number = 4;
        // row = 1;
        // while (row <= number)
        // {
        //     int col = 1;
        //     while (col <= row)
        //     {
        //         cout << row << " ";
        //         col++;
        //     }
        //     cout << endl;
        //     row++;
        // }

        /* (7)
                1
                2 3
                3 4 5
                4 5 6 7
         */
        // number = 4;
        // row = 1;
        // while (row <= number)
        // {
        //     int col = 1;
        //     while (col <= row)
        //     {
        //         cout << row + col - 1 << " ";
        //         col++;
        //     }
        //     cout << endl;
        //     row++;
        // }

        /* (8)
                1
                2 1
                3 2 1
                4 3 2 1
         */
        // number = 4;
        // row = 1;
        // while (row <= number)
        // {
        //     int col = row;
        //     while (col > 0)
        //     {
        //         cout << col << " ";
        //         col--;
        //     }
        //     cout << endl;
        //     row++;
        // }

        /* (9)
                A A A A
                B B B B
                C C C C
                D D D D
        */
        // number = 4;
        // row = 1;
        // while (row <= number)
        // {
        //     int col = 1;
        //     while (col++ <= number)
        //     {
        //         cout << char(64 + row) << " ";
        //     }
        //     cout << endl;
        //     row++;
        // }

        /* (10)
                A B C D
                E F G H
                I J K L
                M N O P
        */
        // number = 4;
        // row = 1;
        // cnt = 65;
        // while (row <= number)
        // {
        //     int col = 1;
        //     while (col++ <= number)
        //     {
        //         cout << char(cnt++) << " ";
        //     }
        //     cout << endl;
        //     row++;
        // }

        /* (11)
                A B C D
                B C D E
                C D E F
                D E F G
        */
        // number = 4;
        // row = 1;
        // cnt = 64;
        // while (row <= number)
        // {
        //     int col = 1;
        //     while (col <= number)
        //     {
        //         cout << char(cnt + row + col++ - 1) << " ";
        //     }
        //     cout << endl;
        //     row++;
        // }

        /* (12)
                A
                B B
                C C C
                D D D D
        */
        //     number = 4;
        //     row = 1;
        //     while (row <= number)
        //     {
        //         int col = 1;
        //         while (col++ <= row)
        //         {
        //             cout << char(64 + row) << " ";
        //         }
        //         cout << endl;
        //         row++;
        //     }

        /* (13)
                A
                B C
                C D E
                D E F G
        */
        // number = 4;
        // row = 1;
        // while (row <= number)
        // {
        //         int col = 1;
        //         while (col <= row)
        //         {
        //                 cout << char(64 + row + col++ - 1) << " ";
        //         }
        //         cout << endl;
        //         row++;
        // }

        /* (14)
                D
                C D
                B C D
                A B C D
        */

        // number = 4;
        // row = 1;
        // cnt = 1;
        // while (row <= number)
        // {
        //         int col = row;
        //         while (col >= 1)
        //         {
        //                 cout << char(64 + number - col + 1) << " ";
        //                 col--;
        //         }
        //         cout << endl;
        //         row++;
        // }

        /* (15)
                A B C D
                B C D E
                C D E F
                D E F G

        */
        // number = 4;
        // row = 1;
        // cnt = 1;
        // while (row <= number)
        // {
        //         int col = 1;
        //         while (col <= number)
        //                 cout << char(64 + col++ + row - 1) << " ";

        //         cout << endl;
        //         row++;
        // }

        /* (16)
         *
         * *
         * * *
         * * * *
         */
        // number = 4;
        // row = 1;
        // while (row <= number)
        // {
        //         // space
        //         int col = number - row;
        //         while (col--)
        //                 cout << "  ";

        //         // print
        //         col = 1;
        //         while (col++ <= row)
        //                 cout << "* ";

        //         cout << endl;
        //         row++;
        // }

        /* (17)
         * * * *
         * * *
         * *
         *
         */
        // number = 4;
        // row = 1;
        // while (row <= number)
        // {
        //         int col = row;
        //         // print
        //         while (col++ <= number)
        //                 cout << "* ";

        //         cout << endl;
        //         row++;
        // }

        /* (18)
         * * * *
         * * *
         * *
         *
         */
        // number = 4;
        // row = 1;
        // while (row <= number)
        // {
        //         // space
        //         int col = row - 1;
        //         while (col-- >= 1)
        //                 cout << "  ";

        //         // print
        //         col = number - row + 1;
        //         while (col-- >= 1)
        //                 cout << "* ";

        //         cout << endl;
        //         row++;
        // }

        /* (19)
                1 1 1 1
                  2 2 2
                    3 3
                      4
         */
        // number = 4;
        // row = 1;
        // while (row <= number)
        // {
        //         // space
        //         int col = row - 1;
        //         while (col-- >= 1)
        //                 cout << "  ";

        //         // print
        //         col = number - row + 1;
        //         while (col-- >= 1)
        //                 cout << row << " ";

        //         cout << endl;
        //         row++;
        // }

        /* (20)
                      1
                    2 3
                  4 5 6
                7 8 9 10

         */
        // number = 4;
        // row = 1;
        // cnt = 1;
        // while (row <= number)
        // {
        //         // space
        //         int col = number - row;
        //         while (col-- >= 1)
        //                 cout << "  ";

        //         // print
        //         col = row ;
        //         while (col-- >= 1)
        //                 cout << cnt++ << " ";

        //         cout << endl;
        //         row++;
        // }

        /* (21)
                1 2 3 4
                  2 3 4
                    3 4
                      4
         */
        // number = 4;
        // row = 1;
        // while (row <= number)
        // {
        //         // space
        //         int col = row - 1;
        //         while (col-- >= 1)
        //                 cout << "  ";

        //         // print
        //         col = number - row + 1;
        //         while (col >= 1)
        //                 cout << number - col-- + 1 << " ";

        //         cout << endl;
        //         row++;
        // }

        /* (22)
                      1
                    1 2 1
                  1 2 3 2 1
                1 2 3 4 3 2 1
         */
        // number = 4;
        // row = 1;
        // while (row <= number)
        // {
        //         // space
        //         int col = number - row;
        //         while (col-- >= 1)
        //                 cout << "  ";

        //         // print first
        //         col = 1;
        //         while (col <= row)
        //                 cout << col++ << " ";

        //         // print second
        //         col = row - 1;
        //         while (col >= 1)
        //                 cout << col-- << " ";
        //         cout << endl;
        //         row++;
        // }

        /* (23)
                1 2 3 4 4 3 2 1
                1 2 3 * * 3 2 1
                1 2 * * * * 2 1
                1 * * * * * * 1
         */
        for (int i = 0; i < num; i++)
        {
                // print Number
                for (int j = 0; j < num - i; j++)
                        cout << j + 1 << " ";

                // print *
                for (int j = 0; j < 2 * i; j++)
                        cout << "* ";

                // print Number
                for (int j = num - i - 1; j >= 0; j--)
                        cout << j + 1 << " ";

                cout << endl;
        }

        /*
                syntaxt
                for(intilization; condi; update){}
        */

        // valid syntaxt
        // for(; cond; upd){}
        // for(; ; upd){}
        // for(; ; ){}

        // for(int a = 0, b=1; cond; upd){}
        // for(int a = 0, b=1; a<10,b<10 ;  upd){}
        // for(int a = 0, b=1; a<10,b<10 ;  a++ , b++){}

        // invalid
        // for(){}

        // for (int first = 0, second = 0; second < 5 && first < 10; first++, second++)
        //         cout << "never run the code first " << first << " second " << second << endl;

        // (1) sum of n number
        // number = 0;
        // cin >> number;

        // sum = 0;
        // for (int i = 1; i <= number; i++)
        // {
        //         sum += i;
        // }
        // cout << "The sum of " << number << " is " << sum << endl;

        // cout << "code ends here" << endl;

        // (2) fibonachhi
        // number = 10;
        // int a = -1, b = 1;

        // // 0 1 1 2 3 5 8 13 21 34
        // for (int i = 1; i <= number; i++)
        // {
        //         int fib = a + b;
        //         a = b;
        //         b = fib;
        //         cout << fib << " ";
        // }

        // **********  continue **********
        // for (int i = 0; i < 10; i++)
        // {
        //         cout << "first line" << endl;
        //         continue; // skip the loop
        //         cout << "second line" << endl;
        // }

        // **********  break **********
        for (int i = 0; i < 10; i++)
        {
                cout << "first line" << endl;
                break; // break the loop
                cout << "second line" << endl;
        }

        int n = 5; // Standard size for patterns

        // ==========================================
        // LEVEL 1: BASIC LOOPS & SUMMATION
        // ==========================================

        // 1. Sum of Odd numbers from 1 to N.
        // 2. Multiples of 3: Print all multiples of 3 up to N.
        // 3. Reverse Count: Print numbers from N down to 1.
        // 4. Power Calculation: Find 2^N using a while loop.

        // ==========================================
        // LEVEL 5: LOGIC & MATH SYMBOLS
        // ==========================================

        /* 14. Binary Staircase (Use if/else)
           1
           0 1
           1 0 1
        */

        /* 15. Number Border (Square with holes)
           1 1 1 1
           1     1
           1     1
           1 1 1 1
        */

        // ==========================================
        // LEVEL 6: COMPLEX MATH & SERIES
        // ==========================================

        // 17. Fibonacci Sequence: Print the first N numbers (0, 1, 1, 2, 3, 5...).
        // 18. Digit Counter: Given a number (e.g., 5021), count how many digits it has.
        // 19. Palindrome Check: Check if a number reads the same forwards and backwards.
        // 20. Diamond Pattern: Combine Challenge 12 and 13 to make a diamond shape.

        return 98;
}