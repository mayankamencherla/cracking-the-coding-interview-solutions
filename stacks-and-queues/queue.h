#include "../linked-lists/linked-list.cpp"
#include <vector>

class Queue
{
    private:
        LinkedList list;

    public:
        // default constructor
        Queue() {}

        Queue(vector<int>& elems);

        void push(int elem);

        int pop();

        int front();

        bool empty();

        int size();
};
