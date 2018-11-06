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
    if (!curr) return nullptr;

    else if (curr->left) return leftMostOf(curr->left);

    return curr;
}

/**
 * The algorithm is to keep going up to the parent
 * Until the current root is a left child of its parent
 *
 * @param TreeNode* root
 * @return TreeNode*
 */
TreeNode* parentOfLeftChild(TreeNode* root)
{
    TreeNode* parent = root->parent;

    if (!parent) return nullptr;

    if (parent->left == root) return parent;

    return parentOfLeftChild(parent);
}

/**
 * Returns the in order successor of root
 *
 * @param TreeNode* root
 * @return TreeNode*
 */
TreeNode* getSuccessor(TreeNode* root)
{
    if (!root) return nullptr;

    TreeNode* successor = leftMostOf(root->right);

    if (successor) return successor;

    return parentOfLeftChild(root);
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

    cout << endl;

    for (int i=1; i<=bst.getNumVertices(); i++)
    {
        TreeNode* node = bst.getNthRank(i);

        TreeNode* successor = getSuccessor(node);

        if (successor == nullptr)
        {
            printf("Node %d doesn't have a successor\n", i);

            cout << endl;

            continue;
        }

        printf("Successor of node %d is %d\n", node->getValue(), successor->getValue());

        cout << endl;
    }
}
