#include "stack.cpp"
#include <limits>
#include <queue>

using namespace std;

/**
 * This is an implementation of a stack by using 2 queues
 */

class QueueOfStacks
{
    private:
        queue<int> q1;
        queue<int> q2;

    public:
        QueueOfStacks() {}

        /**
         * Inserts all elems into the stack
         *
         * @param vector<int>& elems
         */
        QueueOfStacks(vector<int>& elems)
        {
            this->insert(elems);
        }

        /**
         * Insert a group of elements into stacks
         *
         * @param vector<int>& elems
         * @return void
         */
        void insert(vector<int>& elems)
        {
            for (int elem : elems)
            {
                this->insert(elem);
            }
        }

        /**
         * Dequeues all elements in first one by one
         * Queues them into the second queue
         *
         * @param queue<int>& first
         * @param queue<int>& second
         * @return void
         */
        void shiftStacks(queue<int>& first, queue<int>& second)
        {
            while (!first.empty())
            {
                int front = first.front();

                second.push(front);

                first.pop();
            }
        }

        /**
         * Insert an element into stack
         *
         * @param int elem
         * @return void
         */
        void insert(int elem)
        {
            // Queue all elements in q1 into q2
            shiftStacks(q1, q2);

            q1.push(elem);

            // Queue all elements in q2 into q1
            shiftStacks(q2, q1);
        }

        /**
         * Returns the top element of the stack
         *
         * @return int
         */
        int top()
        {
            if (this->isEmpty()) return numeric_limits<int>::max();

            return q1.front();
        }

        /**
         * Pop the top element of the stack
         *
         * @return int
         */
        int pop()
        {
            if (this->isEmpty()) return numeric_limits<int>::min();

            int top = this->top();

            q1.front();

            q1.pop();

            return top;
        }

        /**
         * Return if the size of stack is empty
         *
         * @return bool
         */
        bool isEmpty()
        {
            return (q1.empty()) && (q2.empty());
        }

        /**
         * Returns the number of elements in the stack
         *
         * @return int
         */
        int numElems()
        {
            return q1.size() + q2.size();
        }

        /**
         * Prints all elements in the queue from front to back
         *
         * @return void
         */
        void printQueue()
        {
            for (int i=0; i<numElems(); i++)
            {
                int front = q1.front();

                q1.pop();

                cout << front << " ";

                q1.push(front);
            }

            cout << endl;
        }
};

int main()
{
    vector<int> v = {5, 3, 7, 1, 4};

    QueueOfStacks s = QueueOfStacks(v);

    s.printQueue();

    cout << "Size of the stack " << s.numElems() << endl;

    cout << "Popping the stack " << s.pop() << endl;

    cout << "Popping the stack " << s.pop() << endl;

    cout << "Popping the stack " << s.pop() << endl;

    cout << "Size of the stack " << s.numElems() << endl;

    cout << "Popping the stack " << s.pop() << endl;

    cout << "Popping the stack " << s.pop() << endl;

    cout << "Is the stack empty " << s.isEmpty() << endl;

    cout << "Size of the stack " << s.numElems() << endl;

    cout << "Popping the stack " << s.pop() << endl;
}
