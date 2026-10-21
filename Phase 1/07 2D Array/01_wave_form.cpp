#include <bits/stdc++.h>
using namespace std;

// O(n*n)
void wave_print(vector<vector<int>> &ar)
{
    int row = ar.size();
    int col = ar[0].size();

    for (int i = 0; i < col; i++)
    {
        int s = 0, e = 0;
        if (i % 2 == 0)
        {
            s = 0, e = row;

            while (s < e)
                cout << ar[s++][i] << " ";
        }
        else
        {
            s = row - 1, e = 0;
            while (s >= e)
                cout << ar[s--][i] << " ";
        }
        cout << endl;
    }
}
int main()
{

    vector<vector<int>> ar = {{3, 6, 4, 2},
                              {7, 8, 11, 5},
                              {9, 3, 2, 1},
                              {17, 8, 5, 9}};


    wave_print(ar);
}