// recreateBTreeNode.cpp : Nithin
// Desc: given the pre order and in order traversl of a tree, we generate a new binary tree
//

#include <iostream>
#include <vector>
#include "BinaryTreeNode.hpp"

BTreeNode<int> *RecreateTree(std::vector<int> &inOrder, std::vector<int> &preOrder) {
	if (preOrder.empty())
		return nullptr;

	BTreeNode<int> *root = new BTreeNode<int>(preOrder[0]);
	int rootValue = preOrder[0];
	int rootIndex = 0;

	for (size_t i = 0; i < inOrder.size(); i++) {
		if (inOrder[i] == rootValue) {
			rootIndex = i;
			break;
		}
	}

	std::vector<int> leftInOrder(inOrder.begin(), inOrder.begin() + rootIndex);
	std::vector<int> rightInOrder(inOrder.begin() + rootIndex + 1, inOrder.end());

	std::vector<int> leftPreOrder(preOrder.begin() + 1, preOrder.begin() + 1 + leftInOrder.size());
	std::vector<int> rightPreOrder(preOrder.begin() + 1 + leftInOrder.size(), preOrder.end());

	root->left = RecreateTree(leftInOrder, leftPreOrder);
	root->right = RecreateTree(rightInOrder, rightPreOrder);

	return root;
}

void PrintTreeNode(BTreeNode<int> *root) {
	if (root == nullptr)
		return;

	std::cout << root->value << " ";
	PrintTreeNode(root->left);
	PrintTreeNode(root->right);
}

int main()
{
	std::vector<int> inOrder = { 4, 2, 5, 1, 6, 3, 7 };
	std::vector<int> preOrder = { 1, 2, 4, 5, 3, 6, 7 };

	BTreeNode<int> *root = RecreateTree(inOrder, preOrder);
	PrintTreeNode(root);

	return 0;
}
