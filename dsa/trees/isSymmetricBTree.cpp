// isSymmetricBTree.cpp : nithin
// desc : a simple program to check if a binary tree is symmetric around its center

/*
ex: symmetric b tree

        1
       / \
      2   2
     / \ / \
    3  4 4  3

*/

#include <iostream>

template <typename T>
struct BTreeNode
{
    T value;
    BTreeNode *left;
    BTreeNode *right;

    BTreeNode(const T &v) : value(v), left(nullptr), right(nullptr) {}
};

template <typename T>
bool IsSymmetricHelper(BTreeNode<T> *left, BTreeNode<T> *right)
{
    if (left == nullptr && right == nullptr)
    {
        return true;
    }

    if (left == nullptr || right == nullptr)
    {
        return false;
    }

    if (left->value != right->value)
    {
        return false;
    }

    return IsSymmetricHelper(left->left, right->right) && IsSymmetricHelper(left->right, right->left);
}

template <typename T>
bool IsSymmetric(BTreeNode<T> *root)
{
    if (root == nullptr)
    {
        return true;
    }

    return IsSymmetricHelper(root->left, root->right);
}

template <typename T>
void InOrderTraversal(BTreeNode<T> *root)
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
    BTreeNode<int> *root = new BTreeNode<int>(1);
    root->left = new BTreeNode<int>(2);
    root->right = new BTreeNode<int>(2);

    root->left->left = new BTreeNode<int>(3);
    root->left->right = new BTreeNode<int>(4);

    root->right->left = new BTreeNode<int>(4);
    root->right->right = new BTreeNode<int>(3);

    InOrderTraversal<int>(root);

    bool isSym = IsSymmetric(root);

    std::cout << "\nIs Symmetric: " << isSym << std::endl;

    return 0;
}