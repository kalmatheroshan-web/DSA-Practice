#include <iostream>
#include <queue>
#include <list>
using namespace std;

int main()
{

    queue<int> q;
    q.push(2);
    q.push(4);
    q.push(3);

    cout << q.size() << endl;
    cout << "front " << q.front() << endl;
    cout << "back " << q.back() << endl;
    cout << "is empty " << q.empty() << endl;

    // max heap
    priority_queue<int> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    cout << pq.top() << endl; 

    // min heap
    priority_queue<int, vector<int>, greater<int>> gt;

    deque<int> dq;
    // push_back
    // push_front
    // pop_back
    // pop_front
    // begin, end,rbegin, rend,
    // size
    // clear
    // empty
    // at

    // doubly linked list
    list<int> li;
    li.push_back(10);
    li.push_back(20);
    li.push_back(30);
    cout << li.front() << endl;
    cout << li.back() << endl;
    li.remove(30);
    cout << li.back() << endl;

    return 0;
}