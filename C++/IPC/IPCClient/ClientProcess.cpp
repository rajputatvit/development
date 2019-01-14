#include <iostream>
#include <conio.h>
#include <Windows.h>
//#include <mutex>

using namespace std;
#define MAX_LEN_MSG 256

int main()
{
	//Process Client & Server IPC shared memory can be achieved throigh named events

	// This event will be used when Client will write to shared memory and  Server will wait.
	// h1 event is created in signaled mode
	HANDLE h1 = CreateEvent(NULL, true, true, L"sh_mem");

	// This event will be used when Server will write to shared memory and Client will wait
	HANDLE h12 = CreateEvent(NULL, true, false, L"sh_mem2");

	LPCWSTR memory_object_name = L"shared_memory";
	char msg[] = "Hi I am written from process p1";
	int arr[] = { 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << "Process Client executing" << endl;
	HANDLE  memory_mapped_handle = CreateFileMapping(
		INVALID_HANDLE_VALUE, NULL,
		PAGE_READWRITE,
		0,
		MAX_LEN_MSG,
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


	cout << "Client writing to shared memory" << endl;

	CopyMemory(buf, arr, sizeof(arr));
	cout << "Client finsihed witing into shared memory" << endl;
	cout << "Client signaled event h1 so Server can start its task" << endl;
	Sleep(100000);
	SetEvent(h1);

	cout << "Server is writing in shared memory and Client waiting" << endl;
	WaitForSingleObject(h12, INFINITE);
	cout << "Client got signaled from Server" << endl;
	//CopyMemory((char*)buf, msg, strlen(msg));

	cout << "Client reading updated data: " << endl;
	for (int i = 0; i < 10; i++){
		cout << buf[i] << endl;
		Sleep(10000);
	}

	UnmapViewOfFile(buf);
	CloseHandle(memory_mapped_handle);
	CloseHandle(h1);
	CloseHandle(h12);
	return 0;
}