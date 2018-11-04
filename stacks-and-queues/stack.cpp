#include "stack.h"
#include <limits>

using namespace std;

/**
 * This implementation of a stack uses a LinkedList
 */

/**
 * Creates a stack by inserting an array of elements
 */
Stack::Stack(vector<int>& elems)
{
    for (int elem : elems)
    {
        this->push(elem);
    }
}

/**
 * This method pushes an element onto the top of stack
 *
 * @param int elem
 * @return void
 */
void Stack::push(int elem)
{
    list.insertHead(elem);
};

/**
 * This method retrieves the element on the top of the stack
 *
 * @param void
 * @return int
 */
int Stack::top()
{
    // This is like throwing an exception
    if (list.empty()) return numeric_limits<int>::min();

    return list.getHead()->val;
}

/**
 * This method returns true if the stack is empty, else false
 *
 * @param void
 * @return bool
 */
bool Stack::empty()
{
    return list.empty();
}

/**
 * This method removes the top element of the stack
 *
 * @param void
 * @return int
 */
int Stack::pop()
{
    // This is like throwing an exception
    if (list.empty()) return numeric_limits<int>::min();

    Node* head = list.removeHead();

    int val = head->val;

    delete(head);

    return val;
}

/**
 * This method returns size of the stack
 *
 * @param void
 * @return int
 */
int Stack::size()
{
    return list.getLength();
}
