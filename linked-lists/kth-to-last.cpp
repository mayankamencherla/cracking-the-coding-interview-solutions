#include <vector>
#include <iostream>
#include "linked-list.cpp"

using namespace std;

void printList(LinkedList& l)
{
    Node* curr = l.getHead();

    while (curr)
    {
        cout << curr->val << " ";

        curr = curr->next;
    }

    cout << endl;
}

/**
 * A cheat would be to simply get the length and calculate the nth from last position
 *
 * @param LinkedList l
 * @param int n
 * @return int
 */
int nthFromLastCheat(LinkedList& l, int n)
{
    if (n > l.getLength()) return -1;

    int len = l.getLength();

    int index = len - n ;

    int curr = 0;

    Node* node = l.getHead();

    while (curr < index)
    {
        node = node->next;

        curr++;
    }

    return node->val;
}

int nthFromLastHelper(Node* curr, int n, int& ind)
{
    if (!curr) return -1;

    int deep = nthFromLastHelper(curr->next, n, ind);

    ind++;

    if (ind == n) return curr->val;

    return deep;
}

int nthFromLast(LinkedList& l, int n)
{
    Node* head = l.getHead();

    int curr = 0;

    return nthFromLastHelper(head, n, curr);
}

int main()
{
    vector<int> v = {1, 2, 3, 1, 2, 1, 2, 4, 5, 2, 4, 5, 2, 4};

    LinkedList l = LinkedList();

    for (int elem : v)
    {
        l.addNode(elem);
    }

    cout << "Printing list" << endl;

    printList(l);

    cout << endl;

    int end = v.size();

    for (int i=1; i<=end; i++)
    {
        printf("The %dth from last element is %d\n", i, v[end-i]);

        printf("The %dth from last element using the cheat linked list method is %d\n", i, nthFromLastCheat(l, i));

        printf("The %dth from last element using the linked list method is %d\n", i, nthFromLast(l, i));

        cout << endl;
    }
}
