#include<windows.h>
class ConsoleHandler{
	private:
		HANDLE outhnd;
		HANDLE inhnd;
		SMALL_RECT rect_win;
		CHAR_INFO *buffscreen;
		COORD characterPos;
		COORD buffersize;
		int consoleRangeStartx;
		int consoleRangeStarty;
		POINT p;
	public:
		int fontH;
		int fontW;
		int console_width;
		int console_height;
		ConsoleHandler(int s_width,int s_height);
		void GetWindowPos();
		void display();
		void background(short col = 0);
		void make2DConsole(int fontw = 8, int fonth = 8, LPCTSTR title = (LPCTSTR) "Your Title Here");
		POINT Getpoint();
		int GetconsoleRangeStartx();
		int GetconsoleRangeStarty();
};