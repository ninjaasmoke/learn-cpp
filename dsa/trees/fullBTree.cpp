// fullBTree.cpp : Nithin
// desc : a program to check if a b tree is Full Binary Tree?

/*
It is a special kind of a binary tree that has either zero children or two children. 
It means that all the nodes in that binary tree should either have two child nodes of its parent node or the parent node is itself the leaf node or the external node. 
*/

#include <iostream>
#include "BinaryTreeNode.hpp"
/*
In C++, the difference between #include <filename> and #include "filename" lies in the way the preprocessor locates the file.

    - When you use #include <filename>, the preprocessor looks for the file in the standard system directories. 
        These are typically directories where libraries installed by your system package manager are stored.

    - When you use #include "filename", the preprocessor first looks in the same directory as the current file. 
        If it doesn't find the file there, it then looks in the standard system directories.
*/

template <typename T>
bool IsFullBinaryTree(BTreeNode<T> *root) {
    if (root == nullptr)
        return true;

    if ((root->left != nullptr && root->right != nullptr) || (root->left == nullptr && root->right == nullptr))
        return IsFullBinaryTree(root->left) && IsFullBinaryTree(root->right);   

    return false; 
}

int main()
{
    BTreeNode<int> *root = new BTreeNode<int>(10);

    root->left = new BTreeNode<int>(5);
    root->right = new BTreeNode<int>(15);
    root->left->left = new BTreeNode<int>(3);
    root->left->right = new BTreeNode<int>(7);
    root->right->left = new BTreeNode<int>(12);
    root->right->right = new BTreeNode<int>(18);

    bool isFullBTree = IsFullBinaryTree(root);

    std::cout << "IsFullBinaryTree: " << isFullBTree << std::endl;
    return 0;
}