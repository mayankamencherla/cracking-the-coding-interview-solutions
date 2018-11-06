#include "tree-node.h"
#include <algorithm>

using namespace std;

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

    this->height = 1;
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

    this->left->setParent(this);

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

    this->right->setParent(this);

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

    if (!child) return;

    child->setParent(this);
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

    if (!child) return;

    child->setParent(this);
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

/**
 * Returns the height of the tree
 *
 * @return int
 */
int TreeNode::getHeight()
{
    return this->height;
}

/**
 * Sets the height of the tree
 *
 * @return void
 */
void TreeNode::setHeight()
{
    int heightL = this->left ? this->left->getHeight() : 0;

    int heightR = this->right ? this->right->getHeight() : 0;

    this->height = 1 + max(heightL, heightR);
}

/**
 * Increments the height of the tree
 *
 * @return void
 */
void TreeNode::incrementHeight()
{
    this->height++;
}

/**
 * Gets the parent of the node
 *
 * @return parent
 */
TreeNode* TreeNode::getParent()
{
    return this->parent;
}

/**
 * Sets the parent of the node
 *
 * @param TreeNode* parent
 * @return void
 */
void TreeNode::setParent(TreeNode* parent)
{
    this->parent = parent;
}

/**
 * Returns the value held at this node
 *
 * @return int
 */
int TreeNode::getValue()
{
    return this->value;
}
