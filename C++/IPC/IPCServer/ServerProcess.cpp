
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <mutex>

using namespace std;
#define MAX_LEN_MSG 256

int main()
{
	// h2 event is created to read from shared memory, h2 is non signaled state.
	HANDLE h2 = CreateEvent(NULL, true, false, L"sh_mem");

	//h12 event is created to write into shared memory, h12 is non signaled state.
	HANDLE h12 = CreateEvent(NULL, true, false, L"sh_mem2");

	cout << "Process Server started executing but waiting for signal from Client" << endl;
	WaitForSingleObject(h2, INFINITE);

	LPCWSTR memory_object_name = L"shared_memory";

	HANDLE  memory_mapped_handle = OpenFileMapping(
		FILE_MAP_ALL_ACCESS,
		false,
		memory_object_name
		);

	if (memory_mapped_handle == NULL)
	{
		cout << "Can't create memory object" << endl;
		return 0;
	}

	int *buf = (int*)MapViewOfFile(memory_mapped_handle, FILE_MAP_ALL_ACCESS, 0, 0, MAX_LEN_MSG);

	if (buf == NULL)
	{
		cout << "Can't create mapped view" << endl;
		CloseHandle(memory_mapped_handle);
		return 0;
	}

	cout << "Server reading from shared memory: " << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << buf[i] << endl;
		Sleep(3000);
	}

	cout << "Server is updating data in shared memory: " << endl;
	for (int i = 0; i < 10; i++)
	{
		Sleep(3000);
		buf[i] = buf[i] + 20;
	}

	cout << "Server writing finished and signal event so p1 start reading: " << endl;

	// Signal event to Client
	SetEvent(h12);

	CloseHandle(h2);
	CloseHandle(h12);
	UnmapViewOfFile(buf);
	CloseHandle(memory_mapped_handle);

	return 0;
}