// C++ program to find the length of largest subarray 
// with 0 sum 
#include <iostream> 
#include <unordered_map>
#include <algorithm>
#include "..\x64\Debug\read_input_from_file.h"
using namespace std;


int get_max_sum_of_subarray(vector<int>& vect)
{
	int sum_1st_postive_subgroup = 0;
	int smallest = -9999;
	int n = vect.size();
	//cout << "n: " << n;
	//cout << "debug1";

	for (int i = 0; i < n; ++i)
	{
		//cout << "debug1_1";
		while (i < n && vect[i] >= 0)
		{
			sum_1st_postive_subgroup += vect[i];
			++i;
		}

		if (i >= n)
			return sum_1st_postive_subgroup;

		// cout << sum_1st_postive_subgroup << endl;

		int sum_negtive_subgroup = 0;
		while (i < n && vect[i] < 0)
		{
			sum_negtive_subgroup += vect[i];

			if (vect[i] > smallest)
				smallest = vect[i];
			++i;
		}

		if (i >= n)
		{
			if (sum_1st_postive_subgroup == 0)
				return smallest;
			else
				return sum_1st_postive_subgroup;
		}

		//cout << sum_negtive_subgroup << endl;

		int sum_2nd_postive_subgroup = 0;
		while (i < n && vect[i] >= 0)
		{
			sum_2nd_postive_subgroup += vect[i];
			++i;
		}

		// cout << sum_2nd_postive_subgroup << endl;

		if ((sum_2nd_postive_subgroup + sum_negtive_subgroup) + sum_1st_postive_subgroup >= sum_2nd_postive_subgroup)
			sum_1st_postive_subgroup = sum_negtive_subgroup + sum_1st_postive_subgroup + sum_2nd_postive_subgroup;
		else if (sum_2nd_postive_subgroup >= sum_1st_postive_subgroup)
			sum_1st_postive_subgroup = sum_2nd_postive_subgroup;


		//cout << "value: "<< i << " sum: "<<sum_1st_postive_subgroup << endl;

	}

	//cout << "debug5";
	return sum_1st_postive_subgroup;
}

int main()
{
	// No of test cases
	int no_testcases = 0;
	cin >> no_testcases;

	for (int indx_testcases = 0; indx_testcases < no_testcases; ++indx_testcases)
	{
		// Input size of each test case
		int input_size_testcase = 0;
		cin >> input_size_testcase;

		// Input array
		char*path = "C:\\Users\\37050\\Desktop\\input.txt";
		vector<int>& vect = get_array_from_file(path);
		////vect.reserve(input_size_testcase);

		//for (int indx_vect = 0; indx_vect < input_size_testcase; ++indx_vect)
		//{
		//	int input_array_value;
		//	cin >> input_array_value;
		//	vect[indx_vect] = input_array_value;
		//	//vect.push_back(input_array_value);
		//}
		//cout <<"n: " << vect.size();
		// process input array
		cout << get_max_sum_of_subarray(vect) << endl;

	}

	return 0;
}
