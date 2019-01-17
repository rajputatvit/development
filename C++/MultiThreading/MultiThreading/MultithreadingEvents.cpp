#include <iostream>
#include <Windows.h>
#include <process.h>
#include <math.h>

using namespace std;

volatile int j = 0;
HANDLE hE1;

bool isPrime(int n)
{
	int num = n;

	for (int i = 2; i <= sqrt(n) + 1; ++i)
	{
		if (num % i == 0)
			return 0;
	}

	return 1;
}

unsigned int __stdcall test(void*)
{
	

	
	while (j < 25)
	{
		WaitForSingleObject(hE1, 1000);
		int num = j++;
		char* ch = "NO";

		if (isPrime(num))
			ch = "Yes";

		cout << "Thread: " << GetCurrentThreadId() << " Num: " << num << "  " << ch << endl;
		ReleaseMutex(hE1);
	}

	return 0;
}


int main()
{	
	//HANDLE hE1 = 
	//CreateEvent(NULL, TRUE, false, L"");
	hE1 = CreateMutex(0, 0, 0);
	HANDLE hT1[2];
	 hT1[0] = (HANDLE)_beginthreadex(NULL, 0, test, NULL, 0, NULL);
	 hT1[1] = (HANDLE)_beginthreadex(NULL, 0, test, NULL, 0, NULL);
	 WaitForMultipleObjects(2, hT1, TRUE, 1000);

	CloseHandle(hE1);
	CloseHandle(hT1[0]);
	CloseHandle(hT1[1]);

	return 0;
}