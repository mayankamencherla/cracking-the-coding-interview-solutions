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

        Node* addNode(int val);

        Node* addNode(Node* node);

        void printList();

        void deleteMiddle(Node* node);

        Node* getHead();

        int getLength();
};
