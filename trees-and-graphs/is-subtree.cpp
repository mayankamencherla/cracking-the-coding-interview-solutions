#include "binary-search-tree.cpp"
#include <vector>
#include <iostream>
#include <list>

using namespace std;

/**
 * Write an algorithm to check if T2 is a subtree of T1
 *
 * @see binary-search-tree.cpp
 */

/**
 * Creates a tree of minimal height
 *
 * @param BinarySearchTree& bst
 * @param vectorint>& v
 * @param int start
 * @param int end
 * @return void
 */
void minimalTree(BinarySearchTree& bst, vector<int>& v, int start, int end)
{
    if (start > end) return;

    int mid = (start + end) / 2;

    bst.insert(v[mid]);

    minimalTree(bst, v, start, mid-1);

    minimalTree(bst, v, mid+1, end);
}

/**
 * Creates a tree of minimal height
 *
 * @param BinarySearchTree& bst
 * @param vectorint>& v
 * @return void
 */
void minimalTree(BinarySearchTree& bst, vector<int>& v)
{
    minimalTree(bst, v, 0, v.size()-1);
}

int main()
{
    BinarySearchTree bst = BinarySearchTree();

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    printf("The height of the tree before insertion %d\n", bst.getHeight());

    cout << endl;

    minimalTree(bst, v);

    cout << endl;

    bst.printLevelOrder();

    printf("The height of the tree after insertion %d\n", bst.getHeight());

    cout << endl;

    BinarySearchTree bst2 = BinarySearchTree();

    v = {1, 2, 3, 4, 5, 6, 7};

    printf("The height of the tree before insertion %d\n", bst2.getHeight());

    minimalTree(bst2, v);

    cout << endl;

    bst2.printLevelOrder();

    printf("The height of the tree after insertion %d\n", bst2.getHeight());

    cout << endl;

    printf("Checking if T2 is a subtree of T1 %d\n", bst.isSubtree(bst2.getRoot()));

    printf("Checking if T1 is a subtree of T2 %d\n", bst2.isSubtree(bst.getRoot()));
}
