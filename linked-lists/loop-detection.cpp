#include <iostream>
#include <unordered_set>
#include "linked-list.cpp"

using namespace std;

/**
 * This method checks if the LinkedList has a cycle
 *
 * Space complexity: O(1)
 * Time complexity : O(N)
 *
 * @param LinkedList& l
 * @return bool
 */
bool containsCycle(LinkedList& l)
{
    Node* slow = l.getHead();

    if (!slow) return false;

    Node* fast = slow->next;

    while (fast && fast->next)
    {
        if (slow == fast) return true;

        slow = slow->next;

        fast = fast->next->next;
    }

    return false;
}

int main()
{
    vector<int> v = {1, 2, 3, 1, 2, 1, 2, 4, 5, 2, 4, 5, 2, 4};

    LinkedList l = LinkedList(v);

    cout << "Printing list" << endl;

    // O(N) algorithm to split list around pivot element
    l.printList();

    cout << endl;

    // Creating a cycle in the node
    l.getTail()->next = l.getNodeAt(6);

    cout << "Printing list" << endl;

    unordered_set<Node*> mset;

    Node* curr = l.getHead();

    while (mset.find(curr) == mset.end())
    {
        cout << curr->val << " ";

        mset.insert(curr);

        curr = curr->next;
    }

    cout << endl;

    cout << "Checking whether the lists intersect : " << containsCycle(l) << endl;

    cout << endl;

    cout << "Removing tails next pointer" << endl;

    l.getTail()->next = NULL;

    cout << "Checking whether the lists intersect : " << containsCycle(l) << endl;
}
