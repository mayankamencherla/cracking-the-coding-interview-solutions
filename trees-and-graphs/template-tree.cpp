#include <iostream>

using namespace std;

template <class T>
class TreeNode
{
    private:
        /**
         * Value held at this node
         * @param T val
         */
        T val;

        /**
         * Left child of this node
         * @param TreeNode<T>* left;
         */
        TreeNode<T>* left;

        /**
         * right child of this node
         * @param TreeNode<T>* right;
         */
        TreeNode<T>* right;

    public:
        TreeNode(T value)
        {
            this->val = value;
        }

        /**
         * Returns the value stored at the node
         * @returns val
         */
        T getValue()
        {
            return this->val;
        }
};

int main()
{
    TreeNode<int>* node1 = new TreeNode<int>(1);

    TreeNode<string>* node2 = new TreeNode<string>("mayank");

    TreeNode<long long>* node3 = new TreeNode<long long>(234234234234);

    cout << node1->getValue() << endl;

    cout << node2->getValue() << endl;

    cout << node3->getValue() << endl;
}
