#include "../linked-lists/linked-list.cpp"
#include <vector>

class Stack
{
    private:
        LinkedList list;

    public:
        // default constructor
        Stack() {}

        Stack(vector<int>& elems);

        void push(int elem);

        int pop();

        int top();

        int bottom();

        int popBottom();

        bool empty();

        int size();
};
