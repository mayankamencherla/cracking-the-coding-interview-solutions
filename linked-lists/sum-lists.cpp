#include <vector>
#include <iostream>
#include "linked-list.cpp"

using namespace std;

/**
 * Takes in 2 lists, where curr1 is >= curr2 in length
 * returns their forward sum
 *
 * @param Node* curr1
 * @param Node* curr2
 * @param int diff
 * @return int
 */
int getSum(Node* curr1, Node* curr2, int diff)
{
    // When both nodes are null, the carry is 0
    if (!curr1 && !curr2) return 0;

    int carry;

    if (diff > 0)
    {
        carry = getSum(curr1->next, curr2, diff-1);
    }
    else
    {
        carry = getSum(curr1->next, curr2->next, 0);
    }

    int sum = curr1->val + carry;

    if (diff == 0) sum += curr2->val;

    carry = sum / 10;

    sum %= 10;

    curr1->val = sum;

    return carry;
}

/**
 * Takes in 2 lists and returns their sum
 *
 * @param LinkedList l1
 * @param LinkedList l2
 * @return LinkedList
 */
LinkedList sumForward(LinkedList& l1, LinkedList& l2)
{
    // l1 contains the longer length
    if (l1.getLength() < l2.getLength()) swap(l1, l2);

    // If shorter list is empty, we return the longer list
    if (l2.empty()) return l1;

    int diff = l1.getLength() - l2.getLength();

    // We want the node that is diff distance away from the head
    Node* curr1 = l1.getHead();

    Node* curr2 = l2.getHead();

    // get sum modifies the data pointed at curr1, curr2
    int carry = getSum(curr1, curr2, diff);

    if (carry > 0)
    {
        // The last remaining carry needs to be added into the linked list as the head node (MSB)
        l1.insertHead(carry);
    }

    return l1;
}

int main()
{
    vector<int> v = {6, 1, 7};

    LinkedList l1 = LinkedList(v);

    v = {2, 9, 5};

    printf("Adding 617 and 295 and expected to get 912 \n");

    LinkedList l2 = LinkedList(v);

    LinkedList l = sumForward(l1, l2);

    cout << "Sum 2 lists" << endl;

    l.printList();

    cout << endl;

    v = {9, 9, 9, 9};

    l1 = LinkedList(v);

    l2 = LinkedList(v);

    l = sumForward(l1, l2);

    printf("Adding 9999 and 9999 and expected to get 19998 \n");

    l.printList();

    cout << endl;

    v = {9, 9, 9, 9, 9, 9, 9};

    l1 = LinkedList(v);

    v = {4, 5, 6, 7, 8};

    l2 = LinkedList(v);

    l = sumForward(l1, l2);

    printf("Adding 9999999 and 45678 and expected to get 10045677 \n");

    l.printList();

    cout << endl;

    v = {9, 9, 9, 9, 9, 9, 9};

    l1 = LinkedList(v);

    v = {1};

    l2 = LinkedList(v);

    l = sumForward(l1, l2);

    printf("Adding 9999999 and 1 and expected to get 10000000 \n");

    l.printList();
}
