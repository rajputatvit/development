#include<iostream>
using namespace std;

void findSubArrayWithGivenSum(int *arr, int n, int sum)
{
	for (int j = 0; j<n; ++j)
	{

		int s = sum;
		int i = j;
		cout << j << i << endl;
		while (s - arr[i] >= 0 && i < n)
		{
			
			s -= arr[i];
			i++;
		}

		if (!s)
		{
			cout << "from: " << j + 1 << " to " << i << endl;
			break;
		}
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	findSubArrayWithGivenSum(arr, 10, 15);

	return 0;
}