#include "queue.h"
#include <limits>

using namespace std;

/**
 * This implementation of a queue uses a LinkedList
 */

/**
 * Creates a Queue by inserting an array of elements
 */
Queue::Queue(vector<int>& elems)
{
    for (int elem : elems)
    {
        this->push(elem);
    }
}

/**
 * This method pushes an element onto the back of the queue
 *
 * @param int elem
 * @return void
 */
void Queue::push(int elem)
{
    list.insertHead(elem);
};

/**
 * This method retrieves the element on the front of the queue
 *
 * @param void
 * @return int
 */
int Queue::front()
{
    // This is like throwing an exception
    if (list.empty()) return numeric_limits<int>::min();

    return list.getHead()->val;
}

/**
 * This method returns true if the queue is empty, else false
 *
 * @param void
 * @return bool
 */
bool Queue::empty()
{
    return list.empty();
}

/**
 * This method removes the top element of the queue
 *
 * @param void
 * @return int
 */
int Queue::pop()
{
    // This is like throwing an exception
    if (list.empty()) return numeric_limits<int>::min();

    Node* tail = list.removeTail();

    int val = tail->val;

    delete(tail);

    return val;
}

/**
 * This method returns size of the queue
 *
 * @param void
 * @return int
 */
int Queue::size()
{
    return list.getLength();
}
