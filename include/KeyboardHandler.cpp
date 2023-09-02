#include"headers/KeyboardHandler.h"

bool KeyboardHandler::IsKeyPressed(int keyCode){
	return GetAsyncKeyState(keyCode) & 0x8000;
}

bool KeyboardHandler::IsKeyReleased(int keyCode){
	return !(GetAsyncKeyState(keyCode) & 0x8000);
}

bool KeyboardHandler::CheckForUserExit(){
	return GetAsyncKeyState(VK_ESCAPE);
}