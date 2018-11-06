#include "binary-search-tree.cpp"
#include <vector>
#include <iostream>
#include <list>

using namespace std;

/**
 * Write an algorithm to check if a binary tree is balanced
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

bool isBST(TreeNode* root, int& prev)
{
    if (!root) return true;

    else if (!isBST(root->left, prev)) return false;

    else if (prev != -1 && prev > root->value) return false;

    prev = root->value;

    return isBST(root->right, prev);
}

bool isBST(TreeNode* root)
{
    if (!root) return true;

    int prev = -1;

    return isBST(root, prev);
}

bool isBST(TreeNode* node, int min, int max)
{
    if (!node) return true;

    else if (node->value > max || node->value <= min) return false;

    else if (!isBST(node->left, min, node->value)) return false;

    else if (!isBST(node->right, node->value, max)) return false;

    return true;
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

    printf("Checking to see if the tree is a BST %d\n", isBST(bst.getRoot()));

    cout << endl;

    int min = numeric_limits<int>::min();

    int max = numeric_limits<int>::max();

    printf("Checking to see if the tree is a BST using min/max %d\n", isBST(bst.getRoot(), min, max));
}
