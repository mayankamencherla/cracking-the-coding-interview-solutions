#ifndef TREE_NODE
#define TREE_NODE

class TreeNode
{
    public:
        /**
         * Value held at the node
         *
         * @param int value
         */
        int value;

        /**
         * Left child of the node
         *
         * @param TreeNode* left
         */
        TreeNode* left;

        /**
         * Right child of the node
         *
         * @param TreeNode* right
         */
        TreeNode* right;

        /**
         * Creates a TreeNode* with no children
         *
         * @param int val
         */
        TreeNode(int val);

        /**
         * Adds left child of the node
         * Returns the new left child
         *
         * @param int val
         * @return TreeNode*
         */
        TreeNode* addLeftChild(int val);

        /**
         * Adds right child of the node
         * Returns the new right child
         *
         * @param int val
         * @return TreeNode*
         */
        TreeNode* addRightChild(int val);

        /**
         * Adds a new left child to the TreeNode*
         *
         * @param TreeNode* child
         * @return void
         */
        void setLeftChild(TreeNode* child);

        /**
         * Adds a new right child to the TreeNode*
         *
         * @param TreeNode* child
         * @return void
         */
        void setRightChild(TreeNode* child);

        /**
         * Returns whether the TreeNode* is a leaf
         *
         * @return bool
         */
        bool isLeaf();
};

#endif
