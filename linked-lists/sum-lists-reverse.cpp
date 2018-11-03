#include <vector>
#include <iostream>
#include "linked-list.cpp"

using namespace std;

/**
 * Takes in 2 lists and returns their sum
 *
 * @param LinkedList l1
 * @param LinkedList l2
 * @return LinkedList
 */
LinkedList sumReverse(LinkedList& l1, LinkedList& l2)
{
    // l1 will contain a list >= in length than l2
    if (l1.getLength() < l2.getLength()) swap(l1, l2);

    Node* curr1 = l1.getHead();

    Node* curr2 = l2.getHead();

    // Given that l1 is >= in length than l2,
    // curr2 will reach null before curr1 does

    int carry = 0;

    int sum = 0;

    while (curr2)
    {
        sum = curr1->val + curr2->val + carry;

        carry = sum / 10;

        sum %= 10;

        curr1->val = sum;

        curr1 = curr1->next;

        curr2 = curr2->next;
    }

    while (carry > 0 && curr1)
    {
        sum = carry + curr1->val;

        carry = sum / 10;

        sum %= 10;

        curr1->val = sum;

        curr1 = curr1->next;
    }

    if (!curr1 && carry > 0) l1.addNode(carry);

    return l1;
}

int main()
{
    vector<int> v = {7, 1, 6};

    LinkedList l1 = LinkedList(v);

    v = {5, 9, 2};

    printf("Adding 617 and 295 and expected to get 219 as it is the reverse of 912 \n");

    LinkedList l2 = LinkedList(v);

    LinkedList l = sumReverse(l1, l2);

    cout << "Sum 2 lists in reverse" << endl;

    l.printList();

    cout << endl;

    v = {9, 9, 9, 9};

    l1 = LinkedList(v);

    l2 = LinkedList(v);

    l = sumReverse(l1, l2);

    printf("Adding 9999 and 9999 and expected to get 89991 as it is the reverse of 19998 \n");

    l.printList();

    cout << endl;

    v = {9, 9, 9, 9, 9, 9, 9};

    l1 = LinkedList(v);

    v = {8, 7, 6, 5, 4};

    l2 = LinkedList(v);

    l = sumReverse(l1, l2);

    printf("Adding 9999999 and 45678 and expected to get 77654001 as it is the reverse of 10045677 \n");

    l.printList();

    cout << endl;
}
