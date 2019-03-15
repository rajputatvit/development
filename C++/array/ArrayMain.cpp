#include <iostream>
#include <array>

using namespace std;

int main()
{
	array<int, 4> arr_stl;

	// Capacity
	// 1.
	if (arr_stl.empty())
		cout << "array is empty" << endl;
	// 2.
	cout << "Array max size: " << arr_stl.max_size() << endl;

	// 3.
	cout << "Array size: " << arr_stl.size() << endl;

	// Modifiers
	// 4.
	arr_stl.fill(-1);
	// 5.
	// Create another stl array object similar to old
	array<int, 4> arr_swap = {1, 2, 3, 4};
	arr_stl.swap(arr_swap);

	// Element access
	// 6.
	for (int& x: arr_swap)
	{
		cout << x << endl;
	}
	
	// 7. 
	for (size_t i = 0; i < arr_stl.max_size(); i++)
	{
		cout << arr_stl.at(i) << endl;
		arr_stl.at(i) = i + 1;
		cout << arr_stl.at(i) << endl;
	}

	//8.
	cout << "Front(first): " << arr_stl.front() << endl;
	// 9. 
	cout << "back(last)" << arr_stl.back() << endl;

	// Iterators
	return 0;
}