#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int main()
{
    int arr[] = {2, 1, 2, 3, 3, 4, 4, 4, 5};
    set<int> st;
    for (int ele : arr)
        st.insert(ele); // O(logn)

    cout << "Before : " << endl;
    for (int ele : st)
        cout << ele << " ";

    // remove the 1st element
    // st.erase(st.begin());

    // auto it = st.begin();
    // advance(it, 3);

    // // erase the elements from set in range
    // st.erase(st.begin(), it);

    // delete specific element
    // st.erase(3); // st.erase(element)

    // Delete the entire set
    // st.erase(st.begin(), st.end());

    cout << endl;
    cout << "After : " << endl;

    for (auto ele : st)
        cout << ele << " ";

    set<int> st_ = {1, 5, 7, 8};
    // O(logn)
    auto it1 = st_.find(8);
    auto it2 = st_.find(18); // st.end()

    cout << "\nvalue 1 : " << *it1 << endl;
    cout << "value 2 : " << *it2 << endl;

    unordered_set<int> us;
    us.insert(2); //  O(1)
    us.insert(1);
    us.insert(3);

    for (auto it : us)
        cout << it << " ";
    cout << endl;

    multiset<int> mst = {1, 1, 1, 2, 2, 1, 3, 4, 5, 5, 5, 5, 40};
    for (auto ele : mst)
        cout << ele << " ";
    cout << endl;
    cout << mst.size() << endl;
    mst.erase(2);

    for (auto ele : mst)
        cout << ele << " ";
    cout << endl;

    cout << "Number of 1 in multi set " << mst.count(1) << endl;
    auto it = mst.find(40);
    cout << "ele " << *it << endl;

    mst.clear();
    mst.erase(mst.begin(), mst.end());
    return 0;
}