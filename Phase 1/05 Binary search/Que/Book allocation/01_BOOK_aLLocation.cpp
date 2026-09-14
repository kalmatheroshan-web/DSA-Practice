#include <bits/stdc++.h>
using namespace std;

/*
    BOOK ALLOCATION PROBLEM

    Given:
        ar[i] = number of pages in the ith book
        k     = number of students

    Conditions:
        1. Every student gets at least one book.
        2. Books assigned to a student must be contiguous.
        3. A book cannot be assigned to multiple students.
        4. Every book must be assigned.

    Goal:
        Minimize the maximum number of pages assigned
        to any student.
*/

// APPROACH 1: BRUTE FORCE OVER POSSIBLE ANSWERS

bool canAllocate(int ar[], int n, int k, long long limit)
{
  int students = 1;
  long long pages = 0;

  for (int i = 0; i < n; i++)
  {
    // If a single book itself is larger than limit,
    // allocation is impossible.
    if (ar[i] > limit)
      return false;

    if (pages + ar[i] <= limit)
    {
      pages += ar[i];
    }
    else
    {
      // Give this book to another student.
      students++;
      pages = ar[i];

      if (students > k)
        return false;
    }
  }

  return true;
}

long long findPagesBruteForce(int ar[], int n, int k)
{
  if (k > n)
    return -1;

  long long maximum = 0;
  long long total = 0;

  for (int i = 0; i < n; i++)
  {
    maximum = max(maximum, (long long)ar[i]);
    total += ar[i];
  }

  // Try every possible maximum load.
  for (long long limit = maximum; limit <= total; limit++)
  {
    if (canAllocate(ar, n, k, limit))
      return limit;
  }

  return -1;
}

// ============================================================
// APPROACH 2: RECURSION / BACKTRACKING
// ============================================================

long long solveRecursive(int ar[], int n, int index, int studentsLeft, long long currentMax)
{
  // If this is the last student,
  // give all remaining books to this student.
  if (studentsLeft == 1)
  {
    long long pages = 0;

    for (int i = index; i < n; i++)
    {
      pages += ar[i];
    }

    return max(currentMax, pages);
  }

  long long pages = 0;
  long long answer = -1; // Or LLONG_MAX

  for (int i = index; i <= n - studentsLeft; i++)
  {
    pages += ar[i];

    long long maximumForThisSplit =
        solveRecursive(
            ar,
            n,
            i + 1,
            studentsLeft - 1,
            max(currentMax, pages));

    if (answer == -1)
      answer = maximumForThisSplit;
    else
      answer = min(answer, maximumForThisSplit);
  }

  return answer;
}

long long findPagesRecursive(int ar[], int n, int k)
{
  if (k > n)
    return -1;

  return solveRecursive(
      ar,
      n,
      0,
      k,
      0);
}

// ============================================================
// APPROACH 3: BINARY SEARCH ON ANSWER
// ============================================================

bool isPossible(int ar[], int n, int k, long long limit)
{
  int students = 1;
  long long pages = 0;

  for (int i = 0; i < n; i++)
  {
    // One book itself exceeds the allowed limit.
    if (ar[i] > limit)
      return false;

    if (pages + ar[i] <= limit)
      pages += ar[i];

    else
    {
      // Start a new student.
      students++;
      pages = ar[i];

      if (students > k)
        return false;
    }
  }

  return true;
}

long long findPagesBinarySearch(int ar[], int n, int k)
{
  if (k > n)
    return -1;

  long long low = 0;
  long long high = 0;

  for (int i = 0; i < n; i++)
  {
    low = max(low, (long long)ar[i]);
    high += ar[i];
  }

  long long answer = -1;

  while (low <= high)
  {
    long long mid = low + (high - low) / 2;

    if (isPossible(ar, n, k, mid))
    {
      answer = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }

  return answer;
}

// ============================================================
// VECTOR VERSION
// ============================================================

bool isPossible(const vector<int> &ar, int k, long long limit)
{
  int students = 1;
  long long pages = 0;

  for (int book : ar)
  {
    if (book > limit)
      return false;

    if (pages + book <= limit)
    {
      pages += book;
    }
    else
    {
      students++;
      pages = book;

      if (students > k)
        return false;
    }
  }

  return true;
}

long long findPages(vector<int> &ar, int k)
{
  int n = ar.size();

  if (k > n)
    return -1;

  long long low = 0;
  long long high = 0;

  for (int pages : ar)
  {
    low = max(low, (long long)pages);
    high += pages;
  }

  long long answer = -1;

  while (low <= high)
  {
    long long mid = low + (high - low) / 2;

    if (isPossible(ar, k, mid))
    {
      answer = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }

  return answer;
}

int main()
{
  vector<int> ar = {10, 20, 30, 40};
  int k = 2;

  cout << findPages(ar, k) << endl;

  return 0;
}
