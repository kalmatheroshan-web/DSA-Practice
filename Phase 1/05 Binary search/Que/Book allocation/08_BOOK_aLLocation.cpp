#include <iostream>
#include <vector>

using namespace std;

/*
You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

- Each student receives atleast one book.
- Each student is assigned a contiguous sequence of books.
- No book is assigned to more than one student.
- All books must be allocated

The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

inshort :
    min(max)

 you are trying to assign equal page's book to every std but pages may diff you are trying to assign such that the diff bw the allocation will be mini so that load is balnaced.

*/
// Brute force
int findPages(std::vector<int> &ar, int k)
{
    if (k > ar.size())
    {
        return -1;
    }

    int maxi = 0;
    int sumi = 0;

    for (int val : ar)
    {
        maxi = max(maxi, val);
        sumi += val;
    }

    for (int i = maxi; i <= sumi; ++i)
    {
        int count = 1;
        int cur = 0, page_sum = 0;

        for (int pages : ar)
        {
            page_sum += pages;
            if (page_sum > i)
            {
                count++;
                page_sum = pages;
            }
        }

        if (count <= k)
        {
            return i;
        }
    }

    return -1;
}
// binary search
int findPages(vector<int> &ar, int k)
{

    int len = ar.size();

    if (len < k)
        return -1;

    int st = INT32_MIN, end = 0;

    // find maximum for start and end will be sum of all
    for (int val : ar)
    {
        if (val > st)
            st = val;
        end += val;
    }

    int ans = -1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        int count = 1, page_sum = 0;

        for (int pages : ar)
        {
            page_sum += pages;
            if (page_sum > mid)
            {
                count++;
                page_sum = pages;
            }
        }

        if (count <= k)
        {
            ans = mid;
            end = mid - 1;
        }
        else
            st = mid + 1;
    }

    return ans;
}

/*
    Time : O(n * log(sum−max+1))
    space : O(1)

*/

int main()
{
    vector<int> ar = {2, 3, 4, 7, 11, 12};
    int k = 2;

    int minimum_diff = findPages(ar, k);

    return 0;
}