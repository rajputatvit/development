#include <iostream>
#include <string>

using namespace std;

char FindFirstNonRepeatedChar(char* str)
{
	char count[256] = { 0 };

	int len = strlen(str);

	for (int i = 0; i < len; ++i)
	{
		count[str[i]]++;		
	}

	for (int i = 0; i < len; ++i)
	{
		if (count[str[i]] == 1)
			return str[i];
	}
}

int main()
{
	char* str = "abzddab";

	cout << FindFirstNonRepeatedChar(str);

	return 0;
}