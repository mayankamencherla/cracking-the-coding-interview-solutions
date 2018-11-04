#include "node.cpp"
#include <vector>

using namespace std;

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

        LinkedList(vector<int>& array);

        void deepCopy(LinkedList& other);

        Node* addNode(int val);

        Node* addNode(Node* node);

        void printList();

        void insertHead(int val);

        void insertHead(Node* node);

        void setLength();

        void deleteMiddle(Node* node);

        void partitionList(int val);

        Node* getNodeAt(int index);

        bool empty();

        void initialize();

        void reverse();

        bool isEqual(LinkedList& l);

        Node* getHead();

        Node* getTail();

        int getLength();
};
