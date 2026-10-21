#include <iostream>
using namespace std;

int floorSqrt(int n)
{
    if (n < 4)
        return 1;

    int s = 2, e = n / 2;
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

double sqrtWithPrecision(int n, int precision)
{
    // Step 1: Find integer part
    int s = 0;
    int e = n;
    int ans = 0;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (mid <= n / mid)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    double result = ans;
    double increment = 0.1;

    // Step 2: Find decimal digits
    for (int p = 0; p < precision; p++)
    {
        double candidate = result + increment;

        while (candidate * candidate <= n)
        {
            result = candidate;
            candidate += increment;
        }

        increment /= 10;
    }

    return result;
}

int main()
{

    int num = 16;
    cout << "sqrt of " << num << " : " << floorSqrt(num) << endl;

    return 0;
}