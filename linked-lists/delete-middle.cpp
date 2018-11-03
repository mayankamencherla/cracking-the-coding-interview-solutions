#include <vector>
#include <iostream>
#include "linked-list.cpp"

using namespace std;

/**
 * This method takes a node to delete from the linked list
 * The node is neither the head, nor the tail
 * It deletes this node and keeps the rest of list intact
 *
 * @param Node* node
 * @return void
 */
void deleteMiddle(LinkedList& l, Node* node)
{
    printf("We are deleting node with value %d\n\n", node->val);

    l.deleteMiddle(node);
}

int main()
{
    vector<int> v = {1, 2, 3, 1, 2, 1, 2, 4, 5, 2, 4, 5, 2, 4};

    LinkedList l = LinkedList();

    Node* node;

    // We want the 4th element to be deleted
    int index = 5;

    for (int elem : v)
    {
        if (index == 0) node = l.addNode(elem);

        else l.addNode(elem);

        index--;
    }

    cout << "Printing list" << endl;

    l.printList();

    cout << endl;

    deleteMiddle(l, node);

    cout << "Printing list after deleting middle node" << endl;

    l.printList();

    cout << endl;
}
