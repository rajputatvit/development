#include "TreeHeader.h"

void inorder(BST* root)
{
	if (!root)
		return;

	inorder(root->left);
	cout << root->data << endl;
	inorder(root->right);

	//return;
}