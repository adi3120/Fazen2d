#ifndef MOUSEHANDLER_H
#define MOUSEHANDLER_H

#include"./ConsoleHandler.h"

class MouseHandler {
private:
	bool leftButtonPressed;
    bool rightButtonPressed;
public:
    float GetMouseX();
    float GetMouseY();
	void UpdateMouseState();
    bool IsLeftMousePressed();
    bool IsRightMousePressed();
    bool IsLeftMouseClicked();
    bool IsRightMouseClicked();
};
#endif