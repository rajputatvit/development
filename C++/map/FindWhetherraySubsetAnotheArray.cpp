//Find whether an array is subset of another array

// Output:
// return true if find
// return false if not find

#include <unordered_map>
using namespace std;

bool FindWhetherraySubsetAnotheArray(vector<int> subset_arr1, int n1, vector<int> arr2, int n2)
{
	unordered_map<int, int>hash_map;

	// Create unordered map
	for (int i = 0; i < n2; ++i)
	{
		//hash_map.insert(arr2[i], arr2[i]);
		hash_map[arr2[i]] = arr2[i];
	}

	// Find Subset of subset_arr1 in arr2

	for (int i = 0; i < n1; ++i)
	{
		unordered_map<int, int>::iterator it;
		
		it = hash_map.find(subset_arr1[i]);

		if (it == hash_map.end())
			return false;
	}

	return true;
}