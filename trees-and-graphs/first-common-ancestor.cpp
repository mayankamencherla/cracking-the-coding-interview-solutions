#include "binary-search-tree.cpp"
#include <vector>
#include <iostream>
#include <list>

using namespace std;

/**
 * Write an algorithm to find the first common ancestor in a binary tree
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

/**
 * Start from n, go upwards
 *
 * @param TreeNode* n
 * @param int up
 * @return TreeNode*
 */
TreeNode* goUpBy(TreeNode* n, int up)
{
    if (!n) return nullptr;

    else if (up == 0) return n;

    return goUpBy(n->parent, up-1);
}

/**
 * Given 2 nodes, find their FCA
 *
 * @param TreeNode* n1
 * @param TreeNode* n2
 * @return TreeNode*
 */
TreeNode* firstCommonAncestor(TreeNode* n1, TreeNode* n2)
{
    if (!n1 || !n2) return nullptr;

    if (n1 == n2) return n1;

    int hL = n1->getHeight();

    int hR = n2->getHeight();

    if (hL < hR) swap(n1, n2);

    // Node at lower portion of the tree needs to be moved upwards
    n2 = goUpBy(n2, abs(hL - hR));

    return firstCommonAncestor(n1->parent, n2->parent);
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

    TreeNode* fca = firstCommonAncestor(bst.getNthRank(3), bst.getNthRank(7));

    printf("FCA of 3, 7 is %d\n", fca ? fca->getValue() : -1);

    cout << endl;

    fca = firstCommonAncestor(bst.getNthRank(1), bst.getNthRank(15));

    printf("FCA of 1, 15 is %d\n", fca ? fca->getValue() : -1);

    cout << endl;

    fca = firstCommonAncestor(bst.getNthRank(4), bst.getNthRank(7));

    printf("FCA of 4, 7 is %d\n", fca ? fca->getValue() : -1);

    cout << endl;

    fca = firstCommonAncestor(bst.getNthRank(7), bst.getNthRank(4));

    printf("FCA of 7, 4 is %d\n", fca ? fca->getValue() : -1);

    cout << endl;

    fca = firstCommonAncestor(bst.getNthRank(1), bst.getNthRank(15));

    printf("FCA of 1, 15 is %d\n", fca ? fca->getValue() : -1);

    cout << endl;

    fca = firstCommonAncestor(bst.getNthRank(11), bst.getNthRank(15));

    printf("FCA of 11, 15 is %d\n", fca ? fca->getValue() : -1);

    cout << endl;

    bool isAncestorOf = bst.getNthRank(1)->isAncestorOf(bst.getNthRank(15));

    printf("Checking if 1 is an ancestor of 15 : %d\n", isAncestorOf);

    cout << endl;

    isAncestorOf = bst.getNthRank(8)->isAncestorOf(bst.getNthRank(15));

    printf("Checking if 8 is an ancestor of 15 : %d\n", isAncestorOf);

    cout << endl;
}
