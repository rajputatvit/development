#include "read_input_from_file.h"

vector<int> arr;
int j = 0;

void convertStrtoArr(string str)
{
	// get length of string str 
	int str_length = str.length();

	// create an array with size as string 
	// length and initialize with 0 
	//int arr[str_length] = { 0 };

	int i, sum = 0;

	// Traverse the string 
	for (i = 0; str[i] != '\0'; i++) {

		// if str[i] is ', ' then split 
		if (str[i] == ' ') {

			// Increment j to point to next 
			// array location 
			
			j++;
			arr.push_back(j);
		}
		else {

			// subtract str[i] by 48 to convert it to int 
			// Generate number by multiplying 10 and adding 
			// (int)(str[i]) 
			if (j == 0 && arr.size() == 0)
				arr.push_back(j);

			arr[j] = arr[j] * 10 + (str[i] - 48);
		}
	}

	//cout << "arr[] = ";
	//for (i = 0; i <= j; i++) {
	//	cout << arr[i] << " ";
	//	sum += arr[i]; // sum of array 
	//}

	// print sum of array 
	//cout << "\nSum of array is = " << sum << endl;
}

vector<int>& get_array_from_file(const char* filepath)
{
	
	ifstream readfile;	
	readfile.open(filepath);
	string line;
	while (!readfile.eof())
	{
		getline(readfile, line);
		
		convertStrtoArr(line);
	}

	readfile.close();
	return arr;
}