#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    // step1: create a map
    map<Node *, Node *> m;

    // step2: original list se map kr do copy list ko node by node
    Node *temp = head;
    while (temp)
    {
        m[temp] = new Node(temp->val);
        temp = temp->next;
    }

    // step3: copy random and next pointers from original list
    temp = head;
    while (temp)
    {
        m[temp]->next = m[temp->next];
        m[temp]->random = m[temp->random];
        temp = temp->next;
    }
    return m[head];
}

int main()
{
    return 0;
}
