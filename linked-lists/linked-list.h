#include "node.cpp"

/**
 * This is a LinkedList that holds a integer node
 * It is a singly linked list
 */
class LinkedList
{
    private:
        Node* head;
        Node* tail;
        int length;
    public:
        LinkedList();

        LinkedList(Node* h, Node* t, int l);

        void addNode(int val);

        void addNode(Node* node);

        Node* getHead();

        int getLength();
};
