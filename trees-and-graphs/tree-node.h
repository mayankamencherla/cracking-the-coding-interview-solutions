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
         * Height of the tree rooted at this node
         * Recursively defined as 1 + max(left, right)
         *
         * @param int height
         */
        int height;

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
         * Parent of the node
         *
         * @param TreeNode* parent
         */
        TreeNode* parent;

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

        /**
         * Returns the height of the tree rooted at this node
         *
         * @return int
         */
        int getHeight();

        /**
         * Returns the value held at this node
         *
         * @return int
         */
        int getValue();

        /**
         * Sets the height of the tree rooted at this node
         *
         * @return void
         */
        void setHeight();

        /**
         * Increment the right of this tree
         *
         * @return void
         */
        void incrementHeight();

        /**
         * Gets the parent of the node
         *
         * @return parent
         */
        TreeNode* getParent();

        /**
         * Sets the parent of the node
         *
         * @param TreeNode* parent
         * @return void
         */
        void setParent(TreeNode* parent);
};

#endif
