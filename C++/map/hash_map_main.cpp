// Note: Question related to hashing

#include <iostream>
#include <map>
#include <string>
#include "mapHeader.h"

using namespace std;

int main()
{
	map<string, int> hash_map;
	hash_map.emplace("Anagram", 1);

	for (auto &it : hash_map)
	{
		cout << it.first << " " << it.second << endl;
	}

	cout << "Enter operation" << endl;
	int option;
	cin >> option;
	string output;

	switch (option)
	{
	case 1:	output = fun_anagram("happy", "paphym") ? "Anagram" : "Not_Anagram";
		cout << output << endl;
		break;
	default:
		break;
	}
	
	return 0;
}