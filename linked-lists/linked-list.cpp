#include "linked-list.h"
#include <iostream>
#include <vector>

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

LinkedList::LinkedList(vector<int>& array)
{
    for (int elem : array)
    {
        this->addNode(elem);
    }
}

/**
 * This method takes in a value, and adds it to the tail of the list
 *
 * @param int val
 * @return Node*
 */
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
 * Partitioning list around val
 * All elements <val will come before all elements >=val
 *
 * @param int val
 * @return void
 */
void LinkedList::partitionList(int val)
{
    LinkedList less = LinkedList();

    LinkedList more = LinkedList();

    Node* curr = head;

    while (curr)
    {
        Node* next = curr->next;

        curr->next = NULL;

        if (curr->val < val)
        {
            less.addNode(curr);
        }
        else
        {
            more.addNode(curr);
        }

        curr = next;
    }

    head = less.getHead();

    less.getTail()->next = more.getHead();

    tail = more.getTail();
}

/**
 * This method takes in a value, and adds it to the head of the list
 *
 * @param int val
 * @return void
 */
void LinkedList::insertHead(int val)
{
    Node* node = new Node(val);

    this->insertHead(node);
}

void LinkedList::insertHead(Node* node)
{
    if (!head)
    {
        head = node;

        tail = node;
    }
    else
    {
        node->next = head;

        head = node;
    }

    length++;
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

    if (nodeToDelete == tail) tail = node;

    node->next = nodeToDelete->next;

    nodeToDelete->next = NULL;

    delete(nodeToDelete);

    length--;
}

void LinkedList::printList()
{
    Node* curr = head;

    while (curr)
    {
        cout << curr->val << " ";

        curr = curr->next;
    }

    cout << endl;
}

int LinkedList::getLength()
{
    return length;
}

Node* LinkedList::getHead()
{
    return head;
}

Node* LinkedList::getTail()
{
    return tail;
}
