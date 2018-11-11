/**
 * Design a circular array - that can be efficiently rotated
 * It should also support iteration
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <class T>
class CircularArray
{
    private:
        /**
         * Head of the circular array
         * @param int head
         */
        int head;

        /**
         * The elements in the array
         * vector<T> elements
         */
        vector<T> elements;

        /**
         * Sets the elements array
         * vector<T> v
         */
        void setElements(vector<T>& v)
        {
            this->elements = v;
        }

        /**
         * Gets the elements array
         * @return vector<T> v&
         */
        vector<T>& getElements()
        {
            return this->elements;
        }

        /**
         * Sets the head of the circular array
         */
        void setHead(int head)
        {
            this->head = head;
        }

        /**
         * Gets the head of the circular array
         * @return int
         */
        int getHead()
        {
            this->head = this->head % this->size();

            return this->head;
        }

        /**
         * Increments the head index
         * @return void
         */
        void incrementHead()
        {
            this->rotate(1);
        }

        /**
         * Returns the shifted index
         * @param int index
         * @return int
         */
        int getShiftedIndex(int index)
        {
            return (this->getHead() + index) % (this->size());
        }

    public:
        CircularArray(){}

        CircularArray(vector<T>& v)
        {
            this->setElements(v);

            this->setHead(0);
        }

        /**
         * Rotates the array by shiftRight
         * @param int shiftRight
         */
        void rotate(int shiftRight)
        {
            int h = (this->getHead() + shiftRight) % (this->size());

            this->setHead(h);
        }

        /**
         * Inserts an element into the circular array at the end
         * @param T elem
         * @return void
         */
        void insert(T elem)
        {
            if (this->getHead() == 0)
            {
                this->getElements().push_back(elem);
            }
            else
            {
                this->getElements().insert(this->getElements().begin() + this->getHead(), elem);

                this->incrementHead();
            }
        }

        /**
         * Size of the circular array
         * @return int
         */
        int size()
        {
            return this->getElements().size();
        }

        /**
         * Returns the value at index
         * @param int index
         * @return int
         */
        int get(int index)
        {
            return this->elements[this->getShiftedIndex(index)];
        }

        /**
         * Prints the entire array in circular order
         * @return void
         */
        void print()
        {
            for (int i=0; i<this->size(); i++)
            {
                printf("Getting the element at %d, and is %d\n", i, this->get(i));
            }
        }

        /**
         * Returns an iterator to the head of the circular array
         * @return typename vector<T>::iterator begin
         */
        typename vector<T>::iterator begin()
        {
            return this->getElements().begin() + this->getHead();
        }
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    CircularArray<int> c = CircularArray<int>(v);

    c.rotate(3);

    c.print();

    cout << endl;

    c.insert(8);

    c.print();

    c.rotate(-2);

    cout << endl;

    c.print();

    cout << endl;

    printf("The head of the circular array contains %d\n", *(c.begin()));
}
