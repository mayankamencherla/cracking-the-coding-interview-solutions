#include "stack.cpp"
#include <limits>

using namespace std;

/**
 * This is an implementation of an array being used for 3 stacks
 */

class ThreeInOne
{
    private:
        vector<int> memory;
        int size;
        vector<int> sizes;

    public:
        /**
         * Creates an array that contains 3x size
         * Indices [0,  n-1]  contains stack 1
         * Indices [n,  2n-1] contains stack 2
         * Indices [2n, 3n-1] contains stack 3
         *
         * @param int sz
         */
        ThreeInOne(int sz)
        {
            size = sz;

            memory.resize(3*size, -1);

            // All 3 stacks contain 0 elements
            sizes.resize(3, 0);
        }

        /**
         * Insert an element into stack [0,1,....,stackIndex-1]
         * We can only insert if the stack[stackIndex] is not already full
         *
         * @param int stackIndex
         * @param int elem
         * @return void
         */
        void insert(int stackIndex, int elem)
        {
            if (!isStackValid(stackIndex) || isFull(stackIndex)) return;

            sizes[stackIndex]++;

            int index = getTopIndex(stackIndex);

            memory[index] = elem;
        }

        /**
         * Return the index of the top element of stack at stackIndex
         *
         * @param int stackIndex
         * @return int
         */
        int getTopIndex(int stackIndex)
        {
            return stackIndex*size + sizes[stackIndex] - 1;
        }

        /**
         * Return the element at the top of stack stackIndex
         *
         * @param int stackIndex
         * @return int
         */
        int top(int stackIndex)
        {
            if (!isStackValid(stackIndex) || isEmpty(stackIndex)) return numeric_limits<int>::min();

            int index = getTopIndex(stackIndex);

            return memory[index];
        }

        /**
         * Return the element at the top of stack stackIndex
         * Pop the element from the top of the stack at stackIndex
         *
         * @param int stackIndex
         * @return int
         */
        int pop(int stackIndex)
        {
            if (!isStackValid(stackIndex) || isEmpty(stackIndex)) return numeric_limits<int>::min();

            int index = getTopIndex(stackIndex);

            sizes[stackIndex]--;

            return memory[index];
        }

        /**
         * Return if the size of stack at stackIndex is full
         *
         * @param int stackIndex
         * @return bool
         */
        bool isStackValid(int stackIndex)
        {
            return stackIndex >= 0 && stackIndex <= 2;
        }

        /**
         * Return if the size of stack at stackIndex is full
         *
         * @param int stackIndex
         * @return bool
         */
        bool isFull(int stackIndex)
        {
            return sizes[stackIndex] == size;
        }

        /**
         * Return if the size of stack at stackIndex is empty
         *
         * @param int stackIndex
         * @return bool
         */
        bool isEmpty(int stackIndex)
        {
            return sizes[stackIndex] == 0;
        }
};

int main()
{
    ThreeInOne t = ThreeInOne(10);

    cout << t.pop(0) << endl;

    t.insert(0, 3);

    t.insert(0, 5);

    t.insert(2, 3);

    t.insert(2, 7);

    cout << t.pop(0) << endl;

    cout << t.pop(0) << endl;

    cout << t.pop(2) << endl;

    cout << t.pop(2) << endl;

    cout << t.pop(4) << endl;
}
