#include <vector>
#include <iostream>
#include "linked-list.cpp"

using namespace std;

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
    // Reverses the linked list in O(n)
    LinkedList l2 = l.reverse();

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

    cout << endl;

    v = {1, 2, 3, 2, 1};

    l = LinkedList(v);

    cout << "Printing list" << endl;

    // O(N) algorithm to split list around pivot element
    l.printList();

    cout << endl;

    cout << "Checking if the list is a palindrome " << isPalindrome(l) << endl;
}
