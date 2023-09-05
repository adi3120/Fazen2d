#include "headers/MouseHandler.h"
#include "headers/ConsoleHandler.h"
#include "headers/MathUtils.h"
#include<windows.h>

MouseHandler::MouseHandler(ConsoleHandler& console) : console(console){}

float MouseHandler::GetMouseX()
{
	POINT p=console.Getpoint();
	GetCursorPos(&p);
	console.GetWindowPos();
	p.x = MathUtils::Map(p.x, 0,console.GetConsoleWidth(), console.GetconsoleRangeStartx(), console.GetconsoleRangeStartx() + (console.GetConsoleWidth() - 1) * console.GetFontWidth());
	return p.x;
}
float MouseHandler::GetMouseY()
{
	POINT p=console.Getpoint();
	GetCursorPos(&p);
	console.GetWindowPos();
	p.y = MathUtils::Map(p.y, 0,console.GetConsoleHeight(), console.GetconsoleRangeStarty(), console.GetconsoleRangeStarty() + (console.GetConsoleHeight() - 1) * console.GetFontHeight());
	return p.y;
}
