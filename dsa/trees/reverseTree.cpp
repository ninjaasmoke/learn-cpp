// reverseTree.cpp : Nithin
// desc : a program to reverse a binary tree within a given range

#include <iostream>
#include "BinaryTreeNode.hpp"

void ReverseTreeInRange(BTreeNode<int> *start, BTreeNode<int> *end)
{
	if (start == NULL || end == NULL)
		return;

	if (start == end)
		return;

	BTreeNode<int> *temp = start->left;
	start->left = start->right;
	start->right = temp;

	ReverseTreeInRange(start->left, end);
	ReverseTreeInRange(start->right, end);
}

void PrintTree(BTreeNode<int> *root)
{
	if (root == NULL)
		return;

	PrintTree(root->left);
	std::cout << root->value << " ";
	PrintTree(root->right);
}

int main()
{
	BTreeNode<int> *root = new BTreeNode<int>(1);
	root->left = new BTreeNode<int>(2);
	root->right = new BTreeNode<int>(3);
	root->left->left = new BTreeNode<int>(4);
	root->left->right = new BTreeNode<int>(5);
	root->right->left = new BTreeNode<int>(6);
	root->right->right = new BTreeNode<int>(7);

	PrintTree(root);

	std::cout << std::endl;

	ReverseTreeInRange(root, root->right);

	PrintTree(root);

	return 0;
}
