#include <bits/stdc++.h>
using namespace std;
void subArray(vector<int> &ar)
{
    int n = ar.size();

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            cout << ar[j] << " ";

            cnt++;

            // space
            if (cnt == i + 1)
            {
                cout << "  ";
                if (j < n - 1)
                    j -= cnt - 1;
                cnt = 0;
            }
        }
        cout << endl;
    }
}

int main()
{
    vector<int> ar = {4, 3, 7, 2, 10, 8};
    subArray(ar);
}