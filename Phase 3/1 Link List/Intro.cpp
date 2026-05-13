#include <bits/stdc++.h>
using namespace std;

class node
{
private:
public:
    int data;
    node *next;
    node()
    {
        cout << "called .. " << endl;

        this->data = 0;
        this->next = 0;
    };

    node(int data)
    {
        this->data = data;
        this->next = 0;
    }
};

void insert_first(node *&head, int value)
{
    if (head == 0)
    {
        head = new node(value);
        return;
    }

    node *temp = new node(value);
    temp->next = head;

    head = temp;
}

void insert_mid(node *head, int value, int tar)
{

    node *temp = new node(value);

    if (head == 0)
    {
        head = temp;
        return;
    }

    node *pre = 0;
    while (head)
    {

        if (head && head->data == tar)
        {
            node *temp = new node(value);
            temp->next = head;
            pre->next = temp;
            return;
        }
        pre = head;
        head = head->next;
    }
}

void insert_end(node *head, int value)
{
    if (head == 0)
    {
        head = new node(value);
        return;
    }

    while (head->next)
    {
        head = head->next;
    }
    head->next = new node(value);
}

void traversal(node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


int main()
{

    node a(250);

    node *head = new node(100);

    insert_first(head, 200);
    insert_first(head, 300);

    traversal(head);

    insert_mid(head, 40, 100);

    traversal(head);

    insert_end(head, 89);

    traversal(head);

    return 0;
}