#include <iostream>

using namespace std;

void update(int ar[], int size)
{

    cout << "Inside the function " << endl;

    ar[0] = 100;
    for (int i = 0; i < size; i++)
        cout << ar[i] << " ";
    cout << endl;
    cout << "Outside the function " << endl;
}

int sum_ar(int ar[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += ar[i];
    return sum;
}

int main()
{

    int ar[3] = {10, 20, 30};
    update(ar, 3);

    // printing the data
    for (int i = 0; i < 3; i++)
        cout << ar[i] << " ";
    cout << endl;

    // sum of all element
    int br[5] = {2, 7, 4, -4, 11};

    int output = sum_ar(br, 5);
    cout << "sum of an array " << output << endl;

    return 0;
}