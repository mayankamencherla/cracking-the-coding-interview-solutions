#include <vector>
#include <iostream>
#include "linked-list.cpp"

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 1, 2, 1, 2, 4, 5, 2, 4, 5, 2, 4};

    LinkedList l = LinkedList();

    for (int elem : v)
    {
        l.addNode(elem);
    }

    cout << "Printing list" << endl;

    // O(N) algorithm to split list around pivot element
    l.printList();

    cout << endl;

    // <elements less than 5> <elements greater than or equal to 5>
    l.partitionList(3);

    cout << "Printing list partitionList around 5" << endl;

    l.printList();

    cout << endl;
}
