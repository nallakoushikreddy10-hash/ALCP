#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};


bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;           
        fast = fast->next->next;     

        if (slow == fast)
            return true;
    }

    return false;
}

int main()
{
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> values(n);

    cout << "Enter " << n << " node values: ";

    for (int i = 0; i < n; i++)
        cin >> values[i];


    vector<ListNode*> nodes(n);

    for (int i = 0; i < n; i++)
        nodes[i] = new ListNode(values[i]);


    for (int i = 0; i < n - 1; i++)
        nodes[i]->next = nodes[i + 1];

    ListNode *head = nodes[0];

    int pos;

    cout << "Enter position to connect tail (-1 for no cycle): ";
    cin >> pos;

    if (pos != -1)
        nodes[n - 1]->next = nodes[pos];

    if (hasCycle(head))
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle" << endl;

    return 0;
}