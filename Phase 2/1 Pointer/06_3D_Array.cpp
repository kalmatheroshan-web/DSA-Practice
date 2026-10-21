#include <iostream>
using namespace std;

int main()
{

    int L, B, H;
    cout << "Enter the L,B,H " << endl;
    cin >> L >> B >> H;
    cout << endl;

    int ***p = new int **[L];

    for (int i = 0; i < L; i++)
    {
        p[i] = new int *[B];

        for (int j = 0; j < B; j++)
        {
            p[i][j] = new int[H];
        }
    }

    int cnt = 1;
    // Assising the value
    for (int i = 0; i < L; i++)
        for (int j = 0; j < B; j++)
            for (int k = 0; k < H; k++)
                p[i][j][k] = cnt++;

    // Printing array
    for (int i = 0; i < L; i++)
        for (int j = 0; j < B; j++)
            for (int k = 0; k < H; k++)
                cout << p[i][j][k] << " ";

    // Releasing the memory
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < B; j++)
        {
            delete[] p[i][j];
        }
        delete[] p[i];
    }

    delete[] p;

    return 0;
}