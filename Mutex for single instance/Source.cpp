#include <iostream>
#include <windows.h>

using namespace std;


int main(void)
{
	HANDLE hMutex;
	hMutex = CreateMutex(NULL, FALSE, TEXT("MyMutex"));

	if (hMutex == NULL)			// Null checking for mutex failed
	{
		cout << "Mutex Creation Failed" << endl;
		return -1;
	}

	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		cout << "2nd instance\nAnother instance of the program is running" << endl;
		//cin.get();			// For testing: you can see the other instance is also getting created

		if (hMutex)
			CloseHandle(hMutex);
		return 0;
	}

	cout << "1st Instance \nDo your work this is the first instance" << endl;

	cin.get();

	if (hMutex!= NULL)				// Always check NULL checking before closing any handle
		CloseHandle(hMutex);

	return 0;
}