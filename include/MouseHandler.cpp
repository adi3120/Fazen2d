#include "headers/MouseHandler.h"
#include "headers/ConsoleHandler.h"
#include "headers/MathUtils.h"
#include<windows.h>


float MouseHandler::GetMouseX()
{
	POINT p=ConsoleHandler::Getpoint();
	GetCursorPos(&p);
	ConsoleHandler::GetWindowPos();
	p.x = MathUtils::Map(p.x, 0,ConsoleHandler::GetConsoleWidth(), ConsoleHandler::GetconsoleRangeStartx(), ConsoleHandler::GetconsoleRangeStartx() + (ConsoleHandler::GetConsoleWidth() - 1) * ConsoleHandler::GetFontWidth());
	return p.x;
}
float MouseHandler::GetMouseY()
{
	POINT p=ConsoleHandler::Getpoint();
	GetCursorPos(&p);
	ConsoleHandler::GetWindowPos();
	p.y = MathUtils::Map(p.y, 0,ConsoleHandler::GetConsoleHeight(), ConsoleHandler::GetconsoleRangeStarty(), ConsoleHandler::GetconsoleRangeStarty() + (ConsoleHandler::GetConsoleHeight() - 1) * ConsoleHandler::GetFontHeight());
	return p.y;
}
void MouseHandler::UpdateMouseState()
{
	leftButtonPressed = (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0;
	rightButtonPressed = (GetAsyncKeyState(VK_RBUTTON) & 0x8000) != 0;
}
bool MouseHandler::IsLeftMousePressed()
{
	return leftButtonPressed;
}
bool MouseHandler::IsRightMousePressed()
{
	return rightButtonPressed;
}
bool MouseHandler::IsLeftMouseClicked()
{
	return leftButtonPressed && !IsLeftMousePressed();
}
bool MouseHandler::IsRightMouseClicked()
{
	return rightButtonPressed && !IsRightMousePressed();
}