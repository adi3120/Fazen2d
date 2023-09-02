#ifndef CONSOLEHANDLER_H
#define CONSOLEHANDLER_H
#include<windows.h>

class ConsoleHandler{
	private:
		HANDLE outhnd;
		HANDLE inhnd;
		SMALL_RECT rect_win;
		COORD characterPos;
		COORD buffersize;
		int consoleRangeStartx;
		int consoleRangeStarty;
		POINT p;
	public:
		CHAR_INFO *buffscreen;
		int fontH;
		int fontW;
		int console_width;
		int console_height;
		ConsoleHandler(int s_width,int s_height);
		void GetWindowPos();
		void display();
		void background(short col);
		void make2DConsole(int fontw, int fonth, LPCTSTR title);
		POINT Getpoint();
		int GetconsoleRangeStartx();
		int GetconsoleRangeStarty();
};

#endif 