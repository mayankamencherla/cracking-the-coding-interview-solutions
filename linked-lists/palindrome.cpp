#include <vector>
#include <iostream>
#include <stack>
#include "linked-list.cpp"

using namespace std;

/**
 * This method checks if a LinkedList is a palindrome
 * The algorithm used here is that the list is compared
 * to a reversed LinkedList for equality
 *
 * Space complexity: O(N) to hold values in stack
 * Time complexity : O(N) to create run through elements
 *
 * @param LinkedList& l
 * @return bool
 */
bool isPalindromeStack(LinkedList& l)
{
    int len = l.getLength();

    if (len <= 1) return true;

    stack<int> s;

    Node* curr = l.getHead();

    while (s.size() < len/2)
    {
        s.push(curr->val);

        curr = curr->next;
    }

    // If the length is odd, we advance to the next node
    if (len % 2 == 1) curr = curr->next;

    while (curr)
    {
        int top = s.top();

        s.pop();

        if (top != curr->val) return false;

        curr = curr->next;
    }

    return s.empty();
}

/**
 * This method checks if a LinkedList is a palindrome
 * The algorithm used here is that the list is compared
 * to a reversed LinkedList for equality
 *
 * Space complexity: O(N) to create a new list
 * Time complexity : O(N) to create new list, and compare equality
 *
 * @param LinkedList& l
 * @return bool
 */
bool isPalindrome(LinkedList& l)
{
    LinkedList l2 = LinkedList();

    l2.deepCopy(l);

    // Reverses the linked list in O(n)
    l2.reverse();

    // Checks if 2 lists are equal in O(n)
    return l.isEqual(l2);
}

int main()
{
    vector<int> v = {1, 2, 3, 1, 2, 1, 2, 4, 5, 2, 4, 5, 2, 4};

    LinkedList l = LinkedList(v);

    cout << "Printing list" << endl;

    // O(N) algorithm to split list around pivot element
    l.printList();

    cout << endl;

    cout << "Checking if the list is a palindrome " << isPalindrome(l) << endl;

    cout << "Checking if the list is a palindrome using a stack " << isPalindromeStack(l) << endl;

    cout << endl;

    v = {1, 2, 3, 2, 1};

    l = LinkedList(v);

    cout << "Printing list" << endl;

    // O(N) algorithm to split list around pivot element
    l.printList();

    cout << endl;

    cout << "Checking if the list is a palindrome " << isPalindrome(l) << endl;

    cout << "Checking if the list is a palindrome using a stack " << isPalindromeStack(l) << endl;
}
