#ifndef KEYBOARDHANDLER_H
#define KEYBOARDHANDLER_H

#include <windows.h>

class KeyboardHandler
{
public:
	bool IsKeyPressed(int keyCode);
	bool IsKeyReleased(int keyCode);
	bool CheckForUserExit();
};

#endif