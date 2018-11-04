#include "stack.cpp"
#include <limits>
#include <stack>

using namespace std;

/**
 * This is an implementation of a set of stacks
 * When a stack has reached capacity, we create a new stack
 * When a stack is emptied, we remove the stack from the set
 */

class SetOfStacks
{
    private:
        vector<stack<int>> set;
        int capacity;
        int currStack;

    public:
        /**
         * Creates a new set with capacity per stack
         * The current stack set to the only stack in the set
         *
         * @param int c
         */
        SetOfStacks(int c)
        {
            set.resize(1, stack<int>());

            capacity = c;

            currStack = 0;
        }

        /**
         * Creates a new set with capacity per stack
         * The current stack set to the only stack in the set
         * Inserts all elems into the set
         *
         * @param vector<int>& elems
         * @param int c
         */
        SetOfStacks(vector<int>& elems, int c)
        {
            set.resize(1, stack<int>());

            capacity = c;

            currStack = 0;

            this->insert(elems);
        }

        /**
         * Insert a group of elements into set of stacks
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
         * Adds a new stack to the set,
         * increments the currStack index
         *
         * @return void
         */
        void addStackToSet()
        {
            set.push_back(stack<int>());

            currStack++;
        }

        /**
         * Insert an element into stack
         *
         * @param int elem
         * @return void
         */
        void insert(int elem)
        {
            if (isFull()) addStackToSet();

            set[currStack].push(elem);
        }

        /**
         * Returns the top element of the stack
         *
         * @return int
         */
        int top()
        {
            if (this->isEmpty()) return numeric_limits<int>::max();

            return set[currStack].top();
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

            set[currStack].pop();

            // We leave at least 1 stack in the set
            if (currStack > 0 && set[currStack].empty())
            {
                set.pop_back();

                currStack--;
            }

            return top;
        }

        /**
         * Return if the size of stack is empty
         *
         * @return bool
         */
        bool isEmpty()
        {
            return (currStack == 0) && (set[currStack].empty());
        }

        /**
         * Return if currStack is full
         *
         * @return bool
         */
        bool isFull()
        {
            return (set[currStack].size() == capacity);
        }

        /**
         * Returns the number of stacks
         *
         * @return int
         */
        int numStacks()
        {
            return currStack+1;
        }

        /**
         * Returns the number of full stacks
         *
         * @return int
         */
        int numFullStacks()
        {
            return currStack;
        }

        /**
         * Returns the number of elements in the set
         *
         * @return int
         */
        int numElems()
        {
            return (this->numFullStacks() * capacity) + set[currStack].size();
        }
};

int main()
{
    vector<int> v = {5, 3, 7, 1, 4};

    SetOfStacks s = SetOfStacks(v, 2);

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
