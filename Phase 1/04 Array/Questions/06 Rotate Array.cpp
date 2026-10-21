#include <iostream>
#include <vector>
using namespace std;

void right_rotate(vector<int> &ar, int value = 1)
{
    for (int i = 0; i < value; i++)
    {
        int right = ar.back();
        int len = ar.size();
        for (int j = 1; j < ar.size(); j++)
        {
            ar[len - j] = ar[len - 1 - j];
        }
        ar[0] = right;
    }
}

void left_rotate(vector<int> &ar, int value = 1)
{
    for (int i = 0; i < value; i++)
    {
        int left = ar[0], len = ar.size();
        for (int i = 0; i < len - 1; i++)
            ar[i] = ar[i + 1];

        ar[len - 1] = left;
    }
}

int main()
{
    vector<int> ar = {2, 7, 8, 4, 11, 5};
    for (int val : ar)
        cout << val << " ";
    cout << endl;

    right_rotate(ar, 2);
    for (int val : ar)
        cout << val << " ";

    return 0;
}