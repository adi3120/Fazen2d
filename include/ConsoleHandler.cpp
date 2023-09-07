#include "headers/ConsoleHandler.h"
#include<windows.h>

HANDLE ConsoleHandler::outhnd=0;
HANDLE ConsoleHandler::inhnd=0;
SMALL_RECT ConsoleHandler::rect_win={0,0};
COORD ConsoleHandler::characterPos={0,0};
COORD ConsoleHandler::buffersize={0,0};
int ConsoleHandler::consoleRangeStartx=0;
int ConsoleHandler::consoleRangeStarty=0;
POINT ConsoleHandler::p={0,0};
CHAR_INFO* ConsoleHandler::buffscreen=0;
int ConsoleHandler::fontH=0;
int ConsoleHandler::fontW=0;
int ConsoleHandler::console_width=0;
int ConsoleHandler::console_height=0;

void ConsoleHandler::make2DConsole(int fontw = 8, int fonth = 8)
{
	CONSOLE_FONT_INFOEX fontStructure = {0};
	fontStructure.cbSize = sizeof(fontStructure);
	fontStructure.dwFontSize.X = fontw;
	fontStructure.dwFontSize.Y = fonth;

	SetCurrentConsoleFontEx(outhnd, true, &fontStructure);

	SetConsoleWindowInfo(outhnd, TRUE, &rect_win);
	SetConsoleScreenBufferSize(outhnd, buffersize);

	SetConsoleMode(inhnd, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	fontH = fonth;
	fontW = fontw;
}

ConsoleHandler::ConsoleHandler(int s_width,int s_height){
	console_width=s_width;
	console_height=s_height;
	buffscreen = new CHAR_INFO[console_width * console_height];
	characterPos = {0, 0};
	buffersize = {short(console_width), short(console_height)};
	outhnd = GetStdHandle(STD_OUTPUT_HANDLE);
	inhnd = GetStdHandle(STD_INPUT_HANDLE);
	rect_win = {0, 0, (short)(console_width - 1), short(console_height - 1)};

	this->make2DConsole(8,8);
}

void ConsoleHandler::GetWindowPos(){
	float x;
	float y;
	RECT rect = {};
	GetWindowRect(GetConsoleWindow(), &rect);
	x = rect.left;
	y = rect.top;
	consoleRangeStartx = x;
	consoleRangeStarty = y;
}

POINT ConsoleHandler::Getpoint(){
	return p;
}

int ConsoleHandler::GetconsoleRangeStartx(){
	return consoleRangeStartx;
}

int ConsoleHandler::GetconsoleRangeStarty(){
	return consoleRangeStarty;
}

int ConsoleHandler::GetFontHeight() {
    return fontH;
}

int ConsoleHandler::GetFontWidth() {
    return fontW;
}

int ConsoleHandler::GetConsoleWidth()  {
    return console_width;
}

int ConsoleHandler::GetConsoleHeight() {
    return console_height;
}

HANDLE ConsoleHandler::GetOutHandle()  {
    return outhnd;
}

HANDLE ConsoleHandler::GetInHandle()  {
    return inhnd;
}

SMALL_RECT* ConsoleHandler::GetRectWin() {
	SMALL_RECT* r=&rect_win;
    return r;
}

COORD ConsoleHandler::GetCharacterPos() {
    return characterPos;
}

COORD ConsoleHandler::GetBufferSize()  {
    return buffersize;
}

CHAR_INFO* ConsoleHandler::GetBuffScreen() {
    return buffscreen;
}
