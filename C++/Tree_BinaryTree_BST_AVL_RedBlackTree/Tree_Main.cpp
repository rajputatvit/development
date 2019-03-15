// Note: Question related to Tree

#include <iostream>
#include <map>
#include <string>
#include "TreeHeader.h"

using namespace std;

int main()
{
	map<string, int> hash_map;
	hash_map.emplace("Create Balanced BST from Sorted Array", 1);

	for (auto it = hash_map.begin(); it != hash_map.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}

	cout << "Enter operation" << endl;
	int option;
	cin >> option;
	string output;
	BST* root;
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	switch (option)
	{
	case 1:	
		root = CreateBalancedBSTFromSortedArray(arr, 0, 15);
		// Print output of CreateBalancedBSTFromSortedArray
		inorder(root);
		break;
	default:
		break;
	}

	return 0;
}