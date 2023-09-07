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
