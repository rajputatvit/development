#include <iostream>
#include <Windows.h>
#include <process.h>
#include <math.h>

using namespace std;

class mutex
{
	bool m_bmutex;		// bool to store true or false
	int m_thread_id;	// To store thread id who is taking ownership
public:
	mutex()
	{
		m_bmutex = false;
		m_thread_id = 0;
	}

	void lock()
	{
		if (!m_bmutex)
		{
			m_bmutex = true;
			m_thread_id = GetCurrentThreadId();
		}			
		else
		{
			// Other Thread will wait if someone else is taken mutex ownership
			while (1)
			{
				Sleep(1000);	// sleep

				if (!m_bmutex)
				{
					m_bmutex = true;	// Current thread will take ownership
					m_thread_id = GetCurrentThreadId(); // Update thread id
					break;
				}					
			}
		}
	}

	void unlock()
	{
		if (m_thread_id == GetCurrentThreadId())	// Only owning thread can unlock it
			m_bmutex = false;
	}
};

mutex mtx1;

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
		mtx1.lock();
		int num = j++;
		char* ch = "NO";

		if (isPrime(num))
			ch = "Yes";

		cout << "Thread: " << GetCurrentThreadId() << " Num: " << num << "  " << ch << endl;
		mtx1.unlock();
	}

	return 0;
}


int main()
{
	
	
	HANDLE hT1[3];
	hT1[0] = (HANDLE)_beginthreadex(NULL, 0, test, NULL, 0, NULL);
	hT1[1] = (HANDLE)_beginthreadex(NULL, 0, test, NULL, 0, NULL);
	hT1[2] = (HANDLE)_beginthreadex(NULL, 0, test, NULL, 0, NULL);
	WaitForMultipleObjects(3, hT1, TRUE, 1000);
	
	CloseHandle(hT1[0]);
	CloseHandle(hT1[1]);
	CloseHandle(hT1[2]);

	return 0;
}