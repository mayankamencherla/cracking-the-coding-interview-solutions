#include <iostream>
#include "linked-list.cpp"

using namespace std;

/**
 * This method checks if 2 LinkedLists intersect at a node
 *
 * Space complexity: O(1)
 * Time complexity : O(N)
 *
 * @param LinkedList& l
 * @param LinkedList& l2
 * @return bool
 */
bool doesIntersect(LinkedList& l, LinkedList& l2)
{
    int diff = l.getLength() - l2.getLength();

    if (diff < 0) return doesIntersect(l2, l);

    // l is the longer list, compared to l2

    Node* curr1 = l.getNodeAt(diff);

    Node* curr2 = l2.getHead();

    while (curr1 && curr2)
    {
        if (curr1 == curr2) return true;
#include <iostream>
#include "linked-list.cpp"

using namespace std;

/**
 * This method checks if 2 LinkedLists intersect at a node
 *
 * Space complexity: O(1)
 * Time complexity : O(N)
 *
 * @param LinkedList& l
 * @param LinkedList& l2
 * @return bool
 */
bool doesIntersect(LinkedList& l, LinkedList& l2)
{
    int diff = l.getLength() - l2.getLength();

    if (diff < 0) return doesIntersect(l2, l);

    // l is the longer list, compared to l2

    Node* curr1 = l.getNodeAt(diff);

    Node* curr2 = l2.getHead();

    while (curr1 && curr2)
    {
        if (curr1 == curr2) return true;

        curr1 = curr1->next;

        curr2 = curr2->next;
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

    v = {1, 2, 3, 2, 1};

    LinkedList l2 = LinkedList(v);

    l2.extend(l.getNodeAt(7));

    cout << "Printing list" << endl;

    // O(N) algorithm to split list around pivot element
    l2.printList();

    cout << endl;

    cout << "Checking whether the lists intersect : " << doesIntersect(l, l2) << endl;

    cout << "Checking whether the reverse lists intersect : " << doesIntersect(l2, l) << endl;

    v = {1, 2, 3, 2, 1};

    l2 = LinkedList(v);

    cout << endl;

    cout << "Generated a new list" << endl;

    l2.printList();

    cout << "Checking whether the lists intersect : " << doesIntersect(l, l2) << endl;
}

        curr1 = curr1->next;

        curr2 = curr2->next;
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

    v = {1, 2, 3, 2, 1};

    LinkedList l2 = LinkedList(v);

    // Creating an intersection
    l2.getTail()->next = l.getNodeAt(7);

    l2.setLength();

    cout << "Printing list" << endl;

    // O(N) algorithm to split list around pivot element
    l2.printList();

    cout << endl;

    cout << "Checking whether the lists intersect : " << doesIntersect(l, l2) << endl;

    cout << "Checking whether the reverse lists intersect : " << doesIntersect(l2, l) << endl;

    v = {1, 2, 3, 2, 1};

    l2 = LinkedList(v);

    cout << endl;

    cout << "Generated a new list" << endl;

    l2.printList();

    cout << "Checking whether the lists intersect : " << doesIntersect(l, l2) << endl;
}
