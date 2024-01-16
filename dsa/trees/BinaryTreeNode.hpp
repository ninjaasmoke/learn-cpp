// BinaryTreeNode.hpp : nithin
// desc : a header file that defines a Binary Tree Node

/**
 * A simple binary tree implementation
 * 
 * BTreeNode<int> *root = new BTreeNode(10);
 * 
 * @param value
*/
template <typename T>
struct BTreeNode
{
    T value;
    BTreeNode *left;
    BTreeNode *right;

    BTreeNode(const T &v) : value(v), left(nullptr), right(nullptr) {}
};