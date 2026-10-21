#include <iostream>
using namespace std;

int main()
{
    int row, col;
    cout << "Enter the row and col : " << endl;
    cin >> row >> col;
    cout << endl;

    int **ptr = new int *[row];
    for (int i = 0; i < row; i++)
        ptr[i] = new int[col];

    // asking the value
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> ptr[i][j];

    cout << endl;

    // printing the value
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << ptr[i][j] << " ";
        cout << endl;
    }

    // Releasing the memory from heap
    for (int i = 0; i < row; i++)
        delete[] ptr[i];
        
    delete[] ptr;
}