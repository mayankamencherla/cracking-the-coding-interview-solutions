#include "binary-search-tree.cpp"
#include <vector>
#include <iostream>
#include <list>

using namespace std;

/**
 * Write an algorithm to find the nth rank in the BST
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
 * Returns the left most child of curr
 *
 * @param TreeNode* curr
 * @return TreeNode*
 */
TreeNode* leftMostOf(TreeNode* curr)
{
    if (curr->left) return leftMostOf(curr->left);

    return curr;
}

/**
 * Returns the in order successor of root
 *
 * @param TreeNode* root
 * @return TreeNode*
 */
TreeNode* getSuccessor(TreeNode* root)
{
    if (!root || !root->right) return nullptr;

    return leftMostOf(root->right);
}

int main()
{
    BinarySearchTree bst = BinarySearchTree();

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    printf("The height of the tree before insertion %d\n", bst.getHeight());

    cout << endl;

    minimalTree(bst, v);

    printf("The height of the tree after insertion %d\n", bst.getHeight());

    cout << endl;

    printf("Successor of root %d is %d\n", bst.getRoot()->getValue(), getSuccessor(bst.getRoot())->getValue());
}
