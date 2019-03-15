#include "TreeHeader.h"

// Create balanced BST from sorted array. [Asked in Microsoft Interview]

// Input
// 1. sorted array
// 2. low index
// 3. high index

// Output
// root

BST* CreateBalancedBSTFromSortedArray(int Arr[], int lowIndex, int highIndex)
{
	if (lowIndex > highIndex)
		return NULL;

	BST* root = new BST();
	int midIndex = (lowIndex + highIndex) / 2;
	root->data = Arr[midIndex];
	root->left = CreateBalancedBSTFromSortedArray(Arr, lowIndex, midIndex - 1);
	root->right = CreateBalancedBSTFromSortedArray(Arr, midIndex + 1, highIndex);

	return root;
}