#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str = "abacaabb";

	int n = str.length();
	int len = 0;

	for (int i = 0; i < n -1; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (str[0] == str[j])
			{
				str[0] = str[n - 1];
				str[n - 1] = ' ';
				n--;
				//break;
			}
		}
	}

	cout << "n: " << n << endl;
	cout << "str: " << str << endl;

	return 0;
}