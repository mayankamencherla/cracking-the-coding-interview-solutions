#include "binary-search-tree.cpp"
#include <vector>
#include <iostream>
#include <list>

using namespace std;

/**
 * Write an algorithm to return a list of all levels in the tree
 * The algorithm is written in the BinarySearchTree class
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

    // 15 elements held in 4 levels
    cout << bst.getHeight() << endl;

    minimalTree(bst, v);

    bst.printTree();

    cout << bst.getHeight() << endl;

    cout << endl;

    bst.printLevelOrder();

    cout << endl;

    vector<list> res = bst.levelOrderLists();

    int level = 0;

    for (list l : res)
    {
        printf("Currently printing level %d\n", level);

        for (list::iterator it = l.begin(); it != l.end(); it++)
        {
            cout << *it << " ";
        }

        cout << endl;
    }
}
