// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <thread>
using namespace std;

int sendControlKeyBoardEvent(HWND hwd, int ctrKey, int charKey){
	PostMessage(hwd, WM_SYSKEYDOWN, ctrKey, 0x20380001);
	PostMessage(hwd, WM_SYSKEYDOWN, charKey, 0x203E0001);
	PostMessage(hwd, WM_KEYUP, ctrKey, 0xE0380001);
	PostMessage(hwd, WM_KEYUP, charKey, 0xE03E0001);
	return 0;
}

int openMainProperty(HWND hwd){
	sendControlKeyBoardEvent(hwd, VK_MENU, VK_W);
	std::this_thread::sleep_for(std::chrono::microseconds(500));
	return 0;
}

int openPackage(HWND hwd){
	sendControlKeyBoardEvent(hwd, VK_MENU, VK_E);
	std::this_thread::sleep_for(std::chrono::microseconds(500));
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	HWND mainHwd = ::FindWindowW(L"DHXYMainFrame", NULL);
	std::cout << mainHwd << endl;
	RECT rect;
	GetWindowRect(mainHwd, &rect);

	HWND hwd = FindWindowEx(mainHwd, NULL, L"WSWINDOW", NULL);
	std::cout << hwd << endl;
	GetWindowRect(mainHwd, &rect);
	SendMessage(hwd, WM_LBUTTONDOWN, VK_LBUTTON, 32);
	SendMessage(hwd, WM_LBUTTONUP, 0, 32);
	std::this_thread::sleep_for(std::chrono::seconds(3));
	openMainProperty(hwd);
	std::this_thread::sleep_for(std::chrono::seconds(3));
	openMainProperty(hwd);
	std::this_thread::sleep_for(std::chrono::seconds(3));
	openPackage(hwd);

	return 0;
}

