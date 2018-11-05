#include "stack.cpp"
#include <limits>

using namespace std;

/**
 * This is an implementation of a stack in sorted order
 */

class SortedStack
{
    private:
        Stack s1;
        Stack s2;

    public:
        SortedStack() {}

        /**
         * Inserts all elems into the stack
         *
         * @param vector<int>& elems
         */
        SortedStack(vector<int>& elems)
        {
            this->insert(elems);
        }

        /**
         * Insert a group of elements into stack
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
         * Pops all elements on the first stack, and moves them into buffer
         * Finds the sorted position of elem in the first stack
         *
         * @param Stack& first
         * @param Stack& buffer
         * @param int elem
         * @return void
         */
        void findSortedPosition(Stack& first, Stack& buffer, int elem)
        {
            while (!first.empty() && first.top() > elem)
            {
                int top = first.pop();

                buffer.push(top);
            }
        }

        /**
         * Moves all elements in Stack first into buffer Stack
         *
         * @param Stack& first
         * @param Stack& buffer
         * @return void
         */
        void shiftStacks(Stack& first, Stack& buffer)
        {
            while (!buffer.empty())
            {
                int top = buffer.pop();

                first.push(top);
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
            // Queue all elements in s1 into s2
            findSortedPosition(s1, s2, elem);

            s1.push(elem);

            // Stack all elements in s2 into s1
            shiftStacks(s1, s2);
        }

        /**
         * Returns the top element of the stack
         *
         * @return int
         */
        int top()
        {
            if (this->isEmpty()) return numeric_limits<int>::max();

            return s1.top();
        }

        /**
         * Pop the top element of the stack
         *
         * @return int
         */
        int pop()
        {
            if (this->isEmpty()) return numeric_limits<int>::min();

            return s1.pop();
        }

        /**
         * Return if the size of stack is empty
         *
         * @return bool
         */
        bool isEmpty()
        {
            return (s1.empty()) && (s2.empty());
        }

        /**
         * Returns the number of elements in the stack
         *
         * @return int
         */
        int numElems()
        {
            return s1.size() + s2.size();
        }

        /**
         * Prints all elements in the queue from front to back
         *
         * @return void
         */
        void printStack()
        {
            int sz = this->numElems();

            for (int i=0; i<sz; i++)
            {
                int top = s1.pop();

                cout << top << " ";

                s2.push(top);
            }

            cout << endl;

            for (int i=0; i<sz; i++)
            {
                int top = s2.pop();

                s1.push(top);
            }
        }
};

int main()
{
    vector<int> v = {5, 3, 7, 1, 4};

    for (int elem : v) cout << elem << " ";

    cout << endl;

    SortedStack s = SortedStack(v);

    s.printStack();

    v = {10, 2, 6};

    s.insert(v);

    s.printStack();

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
