#include "headers/ConsoleHandler.h"
#include<windows.h>
void ConsoleHandler::make2DConsole(int fontw = 8, int fonth = 8, LPCTSTR title = (LPCTSTR) "Your Title Here")
{
	CONSOLE_FONT_INFOEX fontStructure = {0};
	fontStructure.cbSize = sizeof(fontStructure);
	fontStructure.dwFontSize.X = fontw;
	fontStructure.dwFontSize.Y = fonth;
	SetConsoleTitle(title);

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
	buffscreen = new CHAR_INFO[s_width * s_height];
	characterPos = {0, 0};
	buffersize = {short(s_width), short(s_height)};
	outhnd = GetStdHandle(STD_OUTPUT_HANDLE);
	inhnd = GetStdHandle(STD_INPUT_HANDLE);
	rect_win = {0, 0, (short)(s_width - 1), short(s_height - 1)};
}

void ConsoleHandler::GetWindowPos(){
	int x;
	int y;
	RECT rect = {};
	GetWindowRect(GetConsoleWindow(), &rect);
	x = rect.left;
	y = rect.top;
	consoleRangeStartx = x;
	consoleRangeStarty = y;
}

POINT ConsoleHandler::Getpoint(){
	return this->p;
}

int ConsoleHandler::GetconsoleRangeStartx(){
	return this->consoleRangeStartx;
}

int ConsoleHandler::GetconsoleRangeStarty(){
	return this->consoleRangeStarty;
}

int ConsoleHandler::GetFontHeight() const {
    return fontH;
}

int ConsoleHandler::GetFontWidth() const {
    return fontW;
}

int ConsoleHandler::GetConsoleWidth() const {
    return console_width;
}

int ConsoleHandler::GetConsoleHeight() const {
    return console_height;
}

HANDLE ConsoleHandler::GetOutHandle() const {
    return outhnd;
}

HANDLE ConsoleHandler::GetInHandle() const {
    return inhnd;
}

SMALL_RECT* ConsoleHandler::GetRectWin() {
	SMALL_RECT* r=&rect_win;
    return r;
}

COORD ConsoleHandler::GetCharacterPos() const {
    return characterPos;
}

COORD ConsoleHandler::GetBufferSize() const {
    return buffersize;
}

CHAR_INFO* ConsoleHandler::GetBuffScreen() const {
    return buffscreen;
}