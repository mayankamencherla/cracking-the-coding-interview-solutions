#include "linked-list.h"

LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
}

LinkedList::LinkedList(Node* h, Node* t)
{
    head = h;
    tail = t;
}

void LinkedList::addNode(int val)
{
    Node* node = new Node(val);

    this->addNode(node);
}

void LinkedList::addNode(Node* node)
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
}

Node* LinkedList::getHead()
{
    return head;
}
