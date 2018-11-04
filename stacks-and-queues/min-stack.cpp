#include "stack.cpp"
#include <limits>
#include <stack>

using namespace std;

/**
 * This is an implementation of a stack that supports O(1) access to min element
 */

class MinStack
{
    private:
        stack<int> main;
        stack<int> min;

    public:
        MinStack() {}

        MinStack(vector<int>& elems)
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
         * Insert an element into stack
         *
         * @param int elem
         * @return void
         */
        void insert(int elem)
        {
            if (this->getMin() >= elem)
            {
                min.push(elem);
            }

            main.push(elem);
        }

        /**
         * Returns the min element in the stack
         *
         * @return int
         */
        int getMin()
        {
            if (this->isEmpty()) return numeric_limits<int>::max();

            return min.top();
        }

        /**
         * Returns the top element of the stack
         *
         * @return int
         */
        int top()
        {
            if (this->isEmpty()) return numeric_limits<int>::max();

            return main.top();
        }

        /**
         * Pop the top element of the stack
         *
         * @return int
         */
        int pop()
        {
            if (this->isEmpty()) return numeric_limits<int>::min();

            if (this->getMin() == this->top()) min.pop();

            int top = this->top();

            main.pop();

            return top;
        }

        /**
         * Return if the size of stack is empty
         *
         * @return bool
         */
        bool isEmpty()
        {
            return main.size() == 0;
        }

        /**
         * Returns the size of the stack
         *
         * @return int
         */
        int size()
        {
            return main.size();
        }
};

int main()
{
    vector<int> v = {5, 3, 7, 1};

    MinStack s = MinStack(v);

    cout << "Min of the stack " << s.getMin() << endl;

    cout << "Popping the stack " << s.pop() << endl;

    cout << "Min of the stack " << s.getMin() << endl;

    cout << "Popping the stack " << s.pop() << endl;

    cout << "Min of the stack " << s.getMin() << endl;

    cout << "Popping the stack " << s.pop() << endl;

    cout << "Min of the stack " << s.getMin() << endl;

    cout << "Popping the stack " << s.pop() << endl;
}
