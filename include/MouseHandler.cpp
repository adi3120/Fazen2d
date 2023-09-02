#include "./MouseHandler.h"
#include "./ConsoleHandler.h"
#include "./MathUtils.h"
#include<windows.h>

MouseHandler::MouseHandler(ConsoleHandler& console) : console(console){}

float MouseHandler::GetMouseX()
{
	POINT p=console.Getpoint();
	GetCursorPos(&p);
	console.GetWindowPos();
	p.x = MathUtils::Map(p.x, 0,console.console_width, console.GetconsoleRangeStartx(), console.GetconsoleRangeStartx() + (console.console_width - 1) * console.fontW);
	return p.x;
}
float MouseHandler::GetMouseY()
{
	POINT p=console.Getpoint();
	GetCursorPos(&p);
	console.GetWindowPos();
	p.x = MathUtils::Map(p.x, 0,console.console_height, console.GetconsoleRangeStarty(), console.GetconsoleRangeStarty() + (console.console_height - 1) * console.fontH);
	return p.y;
}
