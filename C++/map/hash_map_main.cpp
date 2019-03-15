// Note: Question related to hashing

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "mapHeader.h"

using namespace std;

int main()
{
	map<int, string> hash_map;
	hash_map.emplace(1, "Anagram");
	hash_map[2] = "Find whether an array is subset of another array";

	for (auto &it : hash_map)
	{
		cout << it.first << " " << it.second << endl;
	}

	cout << "Enter operation" << endl;
	int option;
	cin >> option;
	string output;

	// 2. 
	vector<int>v1 = { 1, 7 };
	vector<int>v2 = { 1, 4, 5, 2, 3 };

	cout << "***************** Output **********************" << endl;

	switch (option)
	{
	case 1:	output = fun_anagram("happy", "paphym") ? "Anagram" : "Not_Anagram";
		cout << output << endl;
		break;		
	case 2: if (FindWhetherraySubsetAnotheArray(v1, v1.size(), v2, v2.size()))
				cout << "Found subset";
			else
				cout << "Not found subset" << endl;
		break;
	default:
		break;
	}
	
	return 0;
}