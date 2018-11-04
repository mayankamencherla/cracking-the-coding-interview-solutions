#include "linked-list.h"
#include <iostream>
#include <vector>

using namespace std;

LinkedList::LinkedList()
{
    this->initialize();
}

LinkedList::LinkedList(Node* h, Node* t, int l)
{
    head = h;
    tail = t;
    length = l;
}

LinkedList::LinkedList(vector<int>& array)
{
    this->initialize();

    for (int elem : array)
    {
        this->addNode(elem);
    }
}

/**
 * Takes in another LinkedList, and deep copies it into this one
 *
 * @param LinkedList& other
 * @return void
 */
void LinkedList::deepCopy(LinkedList& other)
{
    Node* curr = other.getHead();

    while (curr)
    {
        this->addNode(curr->val);

        curr = curr->next;
    }
}

void LinkedList::initialize()
{
    head = NULL;
    tail = NULL;
    length = 0;
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

    // cout << head->val << " " << tail->val << endl;

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
 * Iteratively converts LinkedList to its reverse
 *
 * @return void
 */
void LinkedList::reverse()
{
    Node* curr = head;

    LinkedList l = LinkedList();

    while (curr)
    {
        Node* next = curr->next;

        curr->next = NULL;

        l.insertHead(curr);

        curr = next;
    }

    head = l.getHead();

    tail = l.getTail();
}

/**
 * This method checks if other LinkedList same as this
 *
 * @param LinkedList& other
 * @return bool
 */
bool LinkedList::isEqual(LinkedList& other)
{
    if (length != other.getLength()) return false;

    Node* curr1 = head;

    Node* curr2 = other.getHead();

    // Both lists are of the same length
    // Therefore, it suffices to check for whether
    // curr1 is null, as it implies a check for curr2

    while (curr1)
    {
        if (curr1->val != curr2->val) return false;

        curr1 = curr1->next;

        curr2 = curr2->next;
    }

    return true;
}

void LinkedList::extend(Node* curr)
{
    tail->next = curr;

    while (curr)
    {
        tail = curr;

        length++;

        curr = curr->next;
    }
}

/**
 * This method removes the head of the list
 *
 * @param void
 * @return Node*
 */
Node* LinkedList::removeHead()
{
    if (!head) return NULL;

    Node* node = head;

    head = node->next;

    length--;

    if (length == 0) tail = NULL;

    node->next = NULL;

    return node;
}

/**
 * This method removes the tail of the list
 *
 * @param void
 * @return Node*
 */
Node* LinkedList::removeTail()
{
    if (length == 0) return NULL;

    length--;

    if (length == 0)
    {
        Node* node = tail;

        head = NULL;

        tail = NULL;

        return node;
    }

    Node* node = head;

    while (node->next != tail)
    {
        node = node->next;
    }

    // Tail points to previous element
    // And node points to tail
    swap(tail, node);

    tail->next = NULL;

    return node;
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

/**
 * Takes in an index in the range [0, length-1]
 * Returns the node at that index
 *
 * @param int index
 * @return Node*
 */
Node* LinkedList::getNodeAt(int index)
{
    Node* curr = head;

    if (index >= length) return NULL;

    else if (index == 0) return head;

    else if (index == length-1) return tail;

    while (index > 0)
    {
        index--;

        curr = curr->next;
    }

    return curr;
}

bool LinkedList::empty()
{
    return length == 0;
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
