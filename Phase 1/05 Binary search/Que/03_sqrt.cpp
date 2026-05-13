#include <iostream>
using namespace std;

int floorSqrt(int n)
{
    if (n < 4)
        return 1;

    int s = 2, e = n;
    int ans = 0;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        int div = n / mid;
        /*
            n = mid*mid
            n/mid = mid
        */
        if (div == mid)
            return mid;
        else if (mid < div)
        {
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }

    return ans;
}

int main()
{

    int num = 16;
    cout << "sqrt of " << num << " : " << floorSqrt(num) << endl;

    return 0;
}