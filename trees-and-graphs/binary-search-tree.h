#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include "tree-node.cpp"
#include <vector>
#include <list>

using namespace std;

class BinarySearchTree
{
    private:
        /**
         * Number of elements in the BST
         *
         * @param int size
         */
        int size;

        /**
         * Root of the Binary Search Tree
         *
         * @param TreeNode* root
         */
        TreeNode* root;

    public:
        /**
         * Creates an empty Binary Search Tree
         *
         * @param void
         */
        BinarySearchTree();

        /**
         * Recursively inserts a new node into the Binary Search Tree
         *
         * @param TreeNode* curr
         * @param int val
         * @return TreeNode*
         */
        TreeNode* recursiveInsert(TreeNode* curr, int val);

        /**
         * Inserts a new node into the Binary Search Tree
         *
         * @param int val
         * @return void
         */
        void insert(int val);

        /**
         * Finds the TreeNode* that contains val, if exists
         *
         * @param TreeNode* curr
         * @param int val
         * @return TreeNode*
         */
        TreeNode* find(TreeNode* curr, int val);

        /**
         * Checks whether a value exists in the BST
         *
         * @param int val
         * @return bool
         */
        bool exists(int val);

        /**
         * Returns the number of vertices in the BST
         *
         * @return int
         */
        int getNumVertices();

        /**
         * Returns the entire tree inOrder
         *
         * @param TreeNode* curr
         * @param vector<int>& res
         * @return void
         */
        void inOrder(TreeNode* curr, vector<int>& res);

        /**
         * Returns the entire tree inOrder
         *
         * @return vector<int>
         */
        vector<int> inOrder();

        /**
         * Returns the entire tree levelOrder
         *
         * @return vector<vector<int>>
         */
        vector<vector<int>> levelOrder();

        /**
         * Returns the entire tree in levelOrder
         * Each level is returned as a linked list
         *
         * @return vector<list<int>>
         */
        vector<list<int>> levelOrderLists();

        /**
         * Prints the entire tree in level order
         *
         * @return void
         */
        void printLevelOrder();

        /**
         * Prints the tree inOrder
         *
         * @return void
         */
        void printTree();

        /**
         * Returns the height of the tree
         *
         * @param TreeNode* curr
         * @return int
         */
        int getHeight(TreeNode* curr);

        /**
         * Returns the height of the tree
         * Height of the root is 1
         *
         * @return int
         */
        int getHeight();

        /**
         * Returns the root of the bst
         *
         * @return TreeNode*
         */
        TreeNode* getRoot();

        /**
         * Returns whether the height of the tree is balanced
         *
         * @param TreeNode* curr
         * @return bool
         */
        bool getBalanced(TreeNode* curr);

        /**
         * Returns whether the height of the tree is balanced
         *
         * @return bool
         */
        bool getBalanced();

        /**
         * Clears the binary tree
         *
         * @return void
         */
        void clear();

        /**
         * Gets the nth rank node by in order
         * n must be in the range [1, numVertices]
         *
         * @param int n
         * @return TreeNode*
         */
        TreeNode* getNthRank(int n);

        /**
         * Gets the nth rank node by in order
         *
         * @param TreeNode* curr
         * @param int& n
         * @return TreeNode*
         */
        TreeNode* getNthRank(TreeNode* curr, int& n);

        /**
         * Returns whether input tree is a subtree of this tree
         *
         * @return bool
         */
        bool isSubtree(TreeNode* tree2);

        /**
         * Returns whether 2 trees are equal
         *
         * @param TreeNode* tree1
         * @param TreeNode* tree2
         * @return bool
         */
        bool areTreesEqual(TreeNode* tree1, TreeNode* tree2);
};

#endif
