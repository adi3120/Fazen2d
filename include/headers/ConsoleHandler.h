#ifndef CONSOLEHANDLER_H
#define CONSOLEHANDLER_H
#include <windows.h>

class ConsoleHandler
{
private:
	HANDLE outhnd;
	HANDLE inhnd;
	SMALL_RECT rect_win;
	COORD characterPos;
	COORD buffersize;
	int consoleRangeStartx;
	int consoleRangeStarty;
	POINT p;
	CHAR_INFO *buffscreen;
	int fontH;
	int fontW;
	int console_width;
	int console_height;

public:
	ConsoleHandler(int s_width, int s_height);
	void GetWindowPos();

	void make2DConsole(int fontw, int fonth, LPCTSTR title);
	POINT Getpoint();
	int GetconsoleRangeStartx();
	int GetconsoleRangeStarty();

	int GetFontHeight() const;		  // Getter for fontH
	int GetFontWidth() const;		  // Getter for fontW
	int GetConsoleWidth() const;	  // Getter for console_width
	int GetConsoleHeight() const;	  // Getter for console_height
	HANDLE GetOutHandle() const;	  // Getter for outhnd
	HANDLE GetInHandle() const;		  // Getter for inhnd
	SMALL_RECT* GetRectWin();	  // Getter for rect_win
	COORD GetCharacterPos() const;	  // Getter for characterPos
	COORD GetBufferSize() const;	  // Getter for buffersize
	CHAR_INFO *GetBuffScreen() const; // Getter for buffscreen
};

#endif