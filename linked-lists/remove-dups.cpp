#include <list>
#include <vector>
#include <iostream>
#include <unordered_set>
#include "linked-list.cpp"

using namespace std;

/**
 * This method takes in a linked list and removes duplicates using a set
 * The set contains all the elements that we have seen so far
 * This method creates a new linked list after deleting elements
 */
LinkedList removeDupsWithBuffer(LinkedList& l)
{
    unordered_set<int> hash;

    LinkedList l2 = LinkedList();

    Node* curr = l.getHead();

    while (curr)
    {
        Node* next = curr->next;

        if (hash.count(curr->val) == 0)
        {
            curr->next = NULL;

            l2.addNode(curr);
        }

        hash.insert(curr->val);

        curr = next;
    }

    return l2;
}

int main()
{
    vector<int> v = {1, 2, 3, 1, 2, 1, 2, 4, 5, 2, 4, 5, 2, 4};

    LinkedList l = LinkedList();

    for (int elem : v)
    {
        l.addNode(elem);
    }

    cout << "Printing list before removing dups" << endl;

    l.printList();

    cout << endl;

    l = removeDupsWithBuffer(l);

    cout << "Printing list after removing dups using buffer" << endl;

    l.printList();
}
