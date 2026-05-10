#include <iostream>
#include <Windows.h>

using namespace std;

int main(void)
{
	HANDLE hSemaphore;
	DWORD lResult;

	hSemaphore = CreateSemaphore(NULL, 3, 3, TEXT("MySemaphore"));
	//hSemaphore = CreateSemaphore(NULL, 3, 3, NULL);


	if (NULL == hSemaphore)
	{
		cout << "CreateSemaphore FAILED" << endl;
		return -1;
	}

	lResult = WaitForSingleObject(hSemaphore, 0);

	if (lResult == WAIT_TIMEOUT)
	{
		cout << "4th Instance: Already another instances are already running" << endl;
		//cin.get();

		if (hSemaphore)
			CloseHandle(hSemaphore);
		return -1;
	}

	cout << " Hello there you get an instance to work on" << endl;

	cin.get();
	ReleaseSemaphore(hSemaphore, 1, NULL);
	CloseHandle(hSemaphore);

	return 0;
}
