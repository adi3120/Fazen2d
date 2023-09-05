#ifndef MOUSEHANDLER_H
#define MOUSEHANDLER_H

#include"./ConsoleHandler.h"

class MouseHandler {
private:
	ConsoleHandler& console;
public:
    MouseHandler(ConsoleHandler& console); 
    float GetMouseX();
    float GetMouseY();
};

#endif