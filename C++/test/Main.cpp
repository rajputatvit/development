/******************************************************************************

Online C++ Compiler.
Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main()
{
	//cout<<"Hello World";

	int arr[256] = { 0 };

	char s1[] = "happy";
	char s2[] = "ypapm";

	int len = strlen(s1);// > strlen(2) ? strlen(s1) : strlen(s2);
	
	for (int i = 0; i<len; ++i)
	{
		//if (s1[])
		arr[s1[i]]++;
		arr[s2[i]]--;
	}

	bool flag = 0;

	for (int i = 0; i<256; ++i)
	{
		if (arr[i] != 0)
		{
			flag = 1;
			break;
		}
	}

	if (flag == 1)
		cout << "Not equal" << endl;
	else
		cout << "equal" << endl;

	return 0;
}
