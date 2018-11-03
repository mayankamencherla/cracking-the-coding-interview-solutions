#include "linked-list.h"

using namespace std;

LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
    length = 0;
}

LinkedList::LinkedList(Node* h, Node* t, int l)
{
    head = h;
    tail = t;
    length = l;
}

Node* LinkedList::addNode(int val)
{
    Node* node = new Node(val);

    return this->addNode(node);
}

Node* LinkedList::addNode(Node* node)
{
    if (!tail)
    {
        head = node;

        tail = node;
    }
    else
    {
        tail->next = node;

        tail = node;
    }

    length++;

    return node;
}

/**
 * Takes a node that is not head, or tail of the list
 * Removes the node from the list and ensures list in order
 *
 * @param Node* node
 * @return void
 */
void LinkedList::deleteMiddle(Node* node)
{
    swap(node->next->val, node->val);

    Node* nodeToDelete = node->next;

    node->next = nodeToDelete->next;

    nodeToDelete->next = NULL;

    delete(nodeToDelete);
}

int LinkedList::getLength()
{
    return length;
}

Node* LinkedList::getHead()
{
    return head;
}
