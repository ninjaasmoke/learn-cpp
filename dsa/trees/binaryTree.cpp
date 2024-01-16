// binaryTree.cpp : nithin
// desc : a simple program to impl a binary tree

#include <iostream>

template <typename T>
struct TreeNode
{
    TreeNode(const T &v) : value(v), left(nullptr), right(nullptr) {}
    T value;
    TreeNode *left;
    TreeNode *right;
};

template <typename T>
void InOrderTraversal(TreeNode<T> *root)
{
    if (root != nullptr)
    {
        InOrderTraversal(root->left);
        std::cout << root->value << " ";
        InOrderTraversal(root->right);
    }
}

int main()
{
    std::cout << "Hello world!\n";

    TreeNode<int> *t = new TreeNode<int>(5);

    t->left = new TreeNode<int>(1);
    t->right = new TreeNode<int>(6);

    InOrderTraversal<int>(t);

    return 0;
}
