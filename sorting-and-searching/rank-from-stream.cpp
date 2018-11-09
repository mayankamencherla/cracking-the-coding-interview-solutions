/**
 * You are reading in a stream of integers, and you wish to
 * look up the rank of a number (#elements <= x)
 * A BST consists of all elements <= root in the left subtree
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

class TreeNode
{
    private:
        /**
         * Number of elements in the left subtree
         * @param int sizeOfLeft
         */
        int sizeOfLeft;

        /**
         * Number of elements in the right subtree
         * @param int sizeOfRight
         */
        int sizeOfRight;

        /**
         * Value of this node
         * @param int value
         */
        int value;

    public:
        TreeNode(int v)
        {
            this->value = v;

            this->left = nullptr;

            this->right = nullptr;

            this->sizeOfLeft = 0;

            this->sizeOfRight = 0;
        }

        /**
         * Left child
         * @param TreeNode* left
         */
        TreeNode* left;

        /**
         * Right child
         * @param TreeNode* right
         */
        TreeNode* right;

        /**
         * Returns the value of this node
         * @returns int
         */
        int getValue()
        {
            return this->value;
        }

        /**
         * Returns the number of elements in the left subtree
         * @returns int
         */
        int getSizeOfLeftSubtree()
        {
            return this->sizeOfLeft;
        }

        /**
         * Increments the size of the left subtree
         * @returns void
         */
        void incrementSizeOfLeft()
        {
            this->sizeOfLeft++;
        }

        /**
         * Increments the size of the right subtree
         * @returns void
         */
        void incrementSizeOfRight()
        {
            this->sizeOfRight++;
        }
};

class StreamRank
{
    private:
        /**
         * The root of the tree
         * @param TreeNode* root
         */
        TreeNode* root;

    public:
        StreamRank()
        {
            this->root = nullptr;
        }

        ~StreamRank()
        {
            delete(this->root);
        }

        StreamRank(vector<int>& v)
        {
            this->root = nullptr;

            for (int elem : v) this->insert(elem);
        }

        /**
         * Creates a new node with value x
         * @param int x
         * @returns TreeNode*
         */
        TreeNode* newNode(int x)
        {
            return new TreeNode(x);
        }

        /**
         * Inserts a new element into the tree
         *
         * @param TreeNode* curr
         * @param int x
         * @returns TreeNode*
         */
        TreeNode* insert(TreeNode* curr, int x)
        {
            if (!curr) return this->newNode(x);

            else if (curr->getValue() >= x)
            {
                curr->left = this->insert(curr->left, x);

                curr->incrementSizeOfLeft();
            }

            else
            {
                curr->right = this->insert(curr->right, x);

                curr->incrementSizeOfRight();
            }

            return curr;
        }

        /**
         * Inserts a new element into the tree
         * @param int x
         * @returns void
         */
        void insert(int x)
        {
            this->root = this->insert(this->root, x);
        }

        /**
         * Adds tracking to a new element
         * @param int x
         * @returns void
         */
        void track(int x)
        {
            this->insert(x);
        }

        /**
         * Retrives the rank of the element
         * @param TreeNode* curr
         * @param int x
         * @returns int
         */
        int getRankOfNumber(TreeNode* curr, int x)
        {
            if (!curr) return 0;

            else if (curr->getValue() <= x) return 1 + curr->getSizeOfLeftSubtree() + this->getRankOfNumber(curr->right, x);

            return this->getRankOfNumber(curr->left, x);
        }

        /**
         * Retrives the rank of the element
         * Rank is defined as the number of elements <= x
         * @param int x
         * @returns int
         */
        int getRankOfNumber(int x)
        {
            return this->getRankOfNumber(this->root, x);
        }

        /**
         * Clears the ranking stream
         * @returns void
         */
        void clear()
        {
            delete(this->root);

            this->root = nullptr;
        }
};

int main()
{
    vector<int> v = {5, 1, 4, 4, 5, 9, 7, 13, 3};

    StreamRank sr = StreamRank(v);

    for (int elem : v)
    {
        printf("What is the rank of %d? It is %d\n", elem, sr.getRankOfNumber(elem));
    }

    cout << endl;

    sr.clear();

    v = {5, 1, 4};

    for (int elem : v) sr.insert(elem);

    for (int elem : v)
    {
        printf("What is the rank of %d? It is %d\n", elem, sr.getRankOfNumber(elem));
    }
}
