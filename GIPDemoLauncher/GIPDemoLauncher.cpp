#include <iostream>
#include <Windows.h>

int main()
{
	//TCHAR lpszClientPath[500] = TEXT("c:\\users\\RikF107\\source\\repos\\GIPDemo\\GIPDemo\\Debug\\GIPDemo.exe");
	//CreateProcess(lpszClientPath, NULL, NULL, NULL, true, HIGH_PRIORITY_CLASS, NULL, NULL, NULL, NULL);

	/*
	STARTUPINFOA *si;
	_PROCESS_INFORMATION *pi;

	memset(&si, 0, sizeof(si));
	memset(&pi, 0, sizeof(pi));

	CreateProcessA("C:\\Users\\RikF107\\source\\repos\\GIPDemo\\GIPDemo\\Debug\\GIPDemo.exe", NULL, NULL, NULL, true, HIGH_PRIORITY_CLASS, NULL, NULL, si, pi);
	*/
	
	
	system("c:\\users\\RikF107\\source\\repos\\GIPDemo\\GIPDemo\\Debug\\GIPDemo.exe");
}