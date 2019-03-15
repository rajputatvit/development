#include <iostream>
using namespace std;

struct BST
{
	int data;
	BST* left;
	BST* right;
};


BST* CreateBalancedBSTFromSortedArray(int Arr[], int lowIndex, int highIndex);

void inorder(BST* root);

