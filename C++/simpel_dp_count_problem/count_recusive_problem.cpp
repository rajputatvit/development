// Note: Question related to hashing

#include <iostream>
#include <vector>

using namespace std;

static int total_recusrion_calls = 0;
int arr_objects[] = { 0, 1, 2, 3 };
int N = 4;
int count(int object, int sum)
{
	cout << "count(" << object << ", " << sum << ") ->";
	total_recusrion_calls++;

	if (object == 0 && sum == 0)
	{
		cout << endl;
		return 1;
	}

	if (object < 0 || sum < 0)
	{
		cout << endl;
		return 0;
	}

	return count(object - 1, sum - arr_objects[0]) + count(object - 1, sum - arr_objects[1]) + count(object - 1, sum - arr_objects[2]) + count(object - 1, sum - arr_objects[3]);

}

int main()
{
	int total_possible_values = count(3, 4);
	cout << "total_recusrion_calls: " << total_recusrion_calls << endl;
	cout << "total_possible_values: " << total_possible_values << endl;

	return 0;
}