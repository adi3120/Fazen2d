#ifndef CONSOLEHANDLER_H
#define CONSOLEHANDLER_H
#include <windows.h>

class ConsoleHandler
{
private:
	static HANDLE outhnd;
	static HANDLE inhnd;
	static SMALL_RECT rect_win;
	static COORD characterPos;
	static COORD buffersize;
	static int consoleRangeStartx;
	static int consoleRangeStarty;
	static POINT p;
	static CHAR_INFO *buffscreen;
	static int fontH;
	static int fontW;
	static int console_width;
	static int console_height;
	ConsoleHandler(){}

public:
	ConsoleHandler(int s_width, int s_height);
	static void GetWindowPos();
	void make2DConsole(int fontw, int fonth);
	static POINT Getpoint();
	static int GetconsoleRangeStartx();
	static int GetconsoleRangeStarty();
	static int GetFontHeight();		  
	static int GetFontWidth();		  
	static int GetConsoleWidth();	  
	static int GetConsoleHeight();	  
	static HANDLE GetOutHandle();	 
	static HANDLE GetInHandle();		  
	static SMALL_RECT* GetRectWin();	  	  
	static COORD GetCharacterPos();	  
	static COORD GetBufferSize();	  
	static CHAR_INFO *GetBuffScreen(); 
};

#endif