#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>> &ar) {

        vector<int> ans;
        if (ar.empty() || ar[0].empty())
            return ans;

        int sr = 0, er = ar.size() - 1;
        int sc = 0, ec = ar[0].size() - 1;

        while (sr <= er && sc <= ec) {

            // Top: Left -> Right
            for (int i = sc; i <= ec; i++)
                ans.push_back(ar[sr][i]);
            sr++;

            // Right: Top -> Bottom
            for (int i = sr; i <= er; i++)
                ans.push_back(ar[i][ec]);
            ec--;

            // Bottom: Right -> Left
            if (sr <= er) {
                for (int i = ec; i >= sc; i--)
                    ans.push_back(ar[er][i]);
                er--;
            }

            // Left: Bottom -> Top
            if (sc <= ec) {
                for (int i = er; i >= sr; i--)
                    ans.push_back(ar[i][sc]);
                sc++;
            }
        }

        return ans;
    }
};

int main() {

    vector<vector<int>> ar = {{1, 2, 3, 4, 5, 6},       {7, 8, 9, 10, 11, 12},
                              {13, 14, 15, 16, 17, 18}, {19, 20, 21, 22, 23, 24},
                              {25, 26, 27, 28, 29, 30}, {31, 32, 33, 34, 35, 36}};

    Solution obj;

    for (int val : obj.spiralOrder(ar))
        cout << val << " ";

    return 0;
}
/*

Links :
        Spiral Matrix II        Medium
        Spiral Matrix III       Medium
        Spiral Matrix IV        Medium
*/
