#include "tree-node.h"

/**
 * Creates a TreeNode* with no children
 *
 * @param int val
 */
TreeNode::TreeNode(int val)
{
    this->value = val;

    this->right = nullptr;

    this->left = nullptr;
}

/**
 * Adds left child of the node
 * Returns the new left child
 *
 * @param int val
 * @return TreeNode*
 */
TreeNode* TreeNode::addLeftChild(int val)
{
    this->left = new TreeNode(val);

    return this->left;
}

/**
 * Adds right child of the node
 * Returns the new right child
 *
 * @param int val
 * @return TreeNode*
 */
TreeNode* TreeNode::addRightChild(int val)
{
    this->right = new TreeNode(val);

    return this->right;
}

/**
 * Adds a new left child to the TreeNode*
 *
 * @param TreeNode* child
 * @return void
 */
void TreeNode::setLeftChild(TreeNode* child)
{
    this->left = child;
}


/**
 * Adds a new right child to the TreeNode*
 *
 * @param TreeNode* child
 * @return void
 */
void TreeNode::setRightChild(TreeNode* child)
{
    this->right = child;
}

/**
 * Returns whether the TreeNode* is a leaf
 *
 * @return bool
 */
bool TreeNode::isLeaf()
{
    return !this->left && !this->right;
}
