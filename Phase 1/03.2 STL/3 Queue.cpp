#include <iostream>
#include <queue>
#include <deque>
#include <list>

using namespace std;

int main()
{
    // ==================================================
    // QUEUE (FIFO - First In First Out)
    // ==================================================

    queue<int> q;     // Empty queue
    queue<int> q2(q); // Copy queue

    // Push
    q.push(10);
    q.push(20);
    q.emplace(30); // Construct in-place

    // Access
    cout << "Front: " << q.front() << endl;
    cout << "Back : " << q.back() << endl;

    // Size
    cout << "Size : " << q.size() << endl;
    cout << "Empty: " << q.empty() << endl;

    // Pop
    q.pop();

    cout << "Front after pop: " << q.front() << endl;

    // Swap
    queue<int> q3;
    q3.push(100);

    q.swap(q3);

    cout << "Front after swap: " << q.front() << endl;

    // Traverse (copy + pop)
    queue<int> tempQ = q;

    cout << "\nQueue: ";
    while (!tempQ.empty())
    {
        cout << tempQ.front() << " ";
        tempQ.pop();
    }
    cout << endl;

    // Clear
    while (!q.empty())
        q.pop();

    // ==================================================
    // PRIORITY QUEUE (MAX HEAP)
    // ==================================================

    priority_queue<int> pq;

    pq.push(5);
    pq.push(1);
    pq.push(8);
    pq.emplace(10);

    cout << "\nMax Heap Top: " << pq.top() << endl;
    cout << "Size: " << pq.size() << endl;

    pq.pop();

    cout << "Top after pop: " << pq.top() << endl;

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(5);
    minHeap.push(1);
    minHeap.push(8);

    cout << "Min Heap Top: " << minHeap.top() << endl;

    // Traverse (copy + pop)
    priority_queue<int> tempPQ = pq;

    cout << "Priority Queue: ";
    while (!tempPQ.empty())
    {
        cout << tempPQ.top() << " ";
        tempPQ.pop();
    }
    cout << endl;

    // ==================================================
    // DEQUE (Double Ended Queue)
    // ==================================================

    deque<int> dq;

    dq.push_back(20);  // Insert back
    dq.push_front(10); // Insert front
    dq.emplace_back(30);
    dq.emplace_front(5);

    cout << "\nFront: " << dq.front() << endl;
    cout << "Back : " << dq.back() << endl;

    cout << "Index 1: " << dq[1] << endl;
    cout << "At(2): " << dq.at(2) << endl;

    // Traverse
    cout << "Deque: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    dq.pop_front(); // Remove front
    dq.pop_back();  // Remove back

    dq.insert(dq.begin() + 1, 100);
    dq.erase(dq.begin());

    cout << "Size : " << dq.size() << endl;
    cout << "Empty: " << dq.empty() << endl;

    dq.clear();
    // push_back
    // push_front
    // pop_back
    // pop_front
    // begin, end,rbegin, rend,
    // size
    // clear
    // empty
    // at

    // ==================================================
    // LIST (Doubly Linked List)
    // ==================================================

    list<int> li;

    li.push_back(20);
    li.push_front(10);
    li.emplace_back(30);
    li.emplace_front(5);

    cout << "\nFront: " << li.front() << endl;
    cout << "Back : " << li.back() << endl;

    cout << "List: ";
    for (int x : li)
        cout << x << " ";
    cout << endl;

    li.pop_front();
    li.pop_back();

    li.insert(li.begin(), 100);
    li.erase(li.begin());

    li.remove(20); // Remove value

    li.reverse(); // Reverse list
    li.sort();    // Sort ascending
    li.unique();  // Remove consecutive duplicates

    cout << "Size : " << li.size() << endl;
    cout << "Empty: " << li.empty() << endl;

    li.clear();

    return 0;
}