#include <string>
#include <windows.h>
#include <sstream>
#include <vector>
#include <chrono>
#include <cmath>
using std::wstring;
#define redF FOREGROUND_RED | FOREGROUND_INTENSITY
#define redB BACKGROUND_RED | BACKGROUND_INTENSITY
#define blueF FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define blueB BACKGROUNDGROUND_BLUE | BACKGROUND_INTENSITY
#define greenF FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define greenB BACKGROUND_GREEN | BACKGROUND_INTENSITY
#define dmagentaF 0x0005
#define magentaF 0x000D
#define yellowF 0x000E
#define dyellowF 0x0006
#define dredF 0x0004
#define greyF 0x0008
#define dgreenF 0x0002
#define whiteF 0x000F
#define whiteB BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY
#define STOP run = false
#define AND_IS_HELD  & 0x80) != 0
#define CHECK_USER_EXIT              \
	if (GetAsyncKeyState(VK_ESCAPE)) \
	{                                \
		break;                       \
	}
#define QUICKTRANSLATE \
	x += center_x;     \
	y += center_y;
#define TIMER                                             \
	tp2 = std::chrono::system_clock::now();               \
	std::chrono::duration<float> elapsedTime = tp2 - tp1; \
	tp1 = tp2;                                            \
	float felapsedTime = elapsedTime.count();
#define TIMEVARS                                 \
	auto tp1 = std::chrono::system_clock::now(); \
	auto tp2 = std::chrono::system_clock::now();

const float pi = 3.141592653589793238;
// if some error related to console_font_infoEx occurs comment this part till the last #endif//
//  typedef struct _CONSOLE_FONT_INFOEX
//  {
//      ULONG cbSize;
//      DWORD nFont;
//      COORD dwFontSize;
//      UINT FontFamily;
//      UINT FontWeight;
//      WCHAR FaceName[LF_FACESIZE];
//  } CONSOLE_FONT_INFOEX, *PCONSOLE_FONT_INFOEX;

// #ifdef __cplusplus
// extern "C"
// {
// #endif
//     BOOL WINAPI SetCurrentConsoleFontEx(HANDLE hConsoleOutput, BOOL bMaximumWindow, PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx);
// #ifdef __cplusplus
// }
// #endif
class Fazen
{
protected:
	HANDLE outhnd;
	HANDLE inhnd;
	SMALL_RECT rect_win;
	CHAR_INFO *buffscreen = new CHAR_INFO[s_width * s_height];
	COORD characterPos = {0, 0};
	COORD buffersize = {short(s_width), short(s_height)};
	float center_x = 0;
	float center_y = 0;
	float tempCenterx;
	float tempCentery;
	int consoleRangeStartx;
	int consoleRangeStarty;
	POINT p;
	int fontH;
	int fontW;

public:
	Fazen()
	{
		outhnd = GetStdHandle(STD_OUTPUT_HANDLE);
		inhnd = GetStdHandle(STD_INPUT_HANDLE);

		rect_win = {0, 0, (short)(s_width - 1), short(s_height - 1)};

		// Enable the window and mouse input events.
	}

	void push()
	{
		tempCenterx = center_x;
		tempCentery = center_y;
	}
	void pop()
	{
		center_x = tempCenterx;
		center_y = tempCentery;
	}
	float mapBounds(float value, float x1, float x2, float y1, float y2)
	{
		float m = (y2 - y1) / (x2 - x1);
		float b = y1 - m * x1;
		value = (value - b) / m;
		return value;
	}
	void GetWindowPos()
	{
		int x;
		int y;
		RECT rect = {};
		GetWindowRect(GetConsoleWindow(), &rect);
		x = rect.left;
		y = rect.top;
		consoleRangeStartx = x;
		consoleRangeStarty = y;
	}
	float Mouse_X()
	{
		GetCursorPos(&p);
		GetWindowPos();
		p.x = mapBounds(p.x, 0, s_width, consoleRangeStartx, consoleRangeStartx + (s_width - 1) * fontW);
		return p.x;
	}
	float Mouse_Y()
	{
		GetCursorPos(&p);
		GetWindowPos();
		p.y = mapBounds(p.y, 0, s_height, consoleRangeStarty, consoleRangeStarty + (s_height - 1) * fontH);
		return p.y - 3;
	}

	const void display()
	{
		WriteConsoleOutputW(outhnd, buffscreen, buffersize, characterPos, &rect_win);
	}
	const void background(short col = 0)
	{
		for (int i = 0; i < s_height * s_width; i++)
		{
			buffscreen[i].Char.UnicodeChar = ' ';
			buffscreen[i].Attributes = col;
		}
	}
	const void Plot(float x, float y, short col = whiteF, short c = 0x2588)
	{
		QUICKTRANSLATE
		if (x > 1 && x < s_width - 1 && y > 1 && y < s_height - 1)
		{
			buffscreen[int(x) + s_width * int(y)].Char.UnicodeChar = c;
			buffscreen[int(x) + s_width * int(y)].Attributes = col;
		}
	}
	// BRESENHAM's LINE ALGO
	void drawLine(float x2, float y2, float x1, float y1, short col = whiteF, short c = 0x2588)
	{
		float x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
		dx = x2 - x1;
		dy = y2 - y1;
		dx1 = std::abs(dx);
		dy1 = std::abs(dy);
		px = 2 * dy1 - dx1;
		py = 2 * dx1 - dy1;
		if (dy1 <= dx1)
		{
			if (dx >= 0)
			{
				x = x1;
				y = y1;
				xe = x2;
			}
			else
			{
				x = x2;
				y = y2;
				xe = x1;
			}

			Plot(x, y, col, c);

			for (i = 0; x < xe; i++)
			{
				x = x + 1;
				if (px < 0)
					px = px + 2 * dy1;
				else
				{
					if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
						y = y + 1;
					else
						y = y - 1;
					px = px + 2 * (dy1 - dx1);
				}
				Plot(x, y, col, c);
			}
		}
		else
		{
			if (dy >= 0)
			{
				x = x1;
				y = y1;
				ye = y2;
			}
			else
			{
				x = x2;
				y = y2;
				ye = y1;
			}

			Plot(x, y, col, c);

			for (i = 0; y < ye; i++)
			{
				y = y + 1;
				if (py <= 0)
					py = py + 2 * dx1;
				else
				{
					if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
						x = x + 1;
					else
						x = x - 1;
					py = py + 2 * (dx1 - dy1);
				}
				Plot(x, y, col, c);
			}
		}
	}

	void translate(float x, float y)
	{
		center_x = x;
		center_y = y;
	}

	const void drawTextFromInt(int x, int y, wstring s, int b, short col = whiteF)
	{
		QUICKTRANSLATE
		std::wostringstream ws;
		ws << b;

		std::wstring a = s + (ws.str());

		for (size_t i = 0; i < a.size(); i++)
		{
			buffscreen[x + i + s_width * y].Char.UnicodeChar = a[i];
			buffscreen[x + i + s_width * y].Attributes = col;
		}
	}
	const void Text(int x, int y, wstring a, short col = whiteF)
	{
		QUICKTRANSLATE
		for (size_t i = 0; i < a.size(); i++)
		{
			buffscreen[x + i + s_width * y].Char.UnicodeChar = a[i];
			buffscreen[x + i + s_width * y].Attributes = col;
		}
	}
}

;

class Fazen2d : public Fazen
{
public:
	const void make2DConsole(int fontw = 8, int fonth = 8, LPCTSTR title = (LPCTSTR) "Your Title Here")
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

	const void drawRectangle(float x, float y, int b_width, int b_height, float angle = 0, short col = whiteF,int border=0,short bordCol=greenF)
	{
		// float tempx;
		// float tempy;
		// const float xoffset = -b_width / 2;
		// const float yoffset = -b_height / 2;
		// for (float i = 0; i <= b_height; i += 0.1)
		// {
		// 	for (float j = 0; j <= b_width; j += 0.1)
		// 	{
		// 		tempx = ((xoffset + j) * cos(angle) - (yoffset + i) * sin(angle));
		// 		tempy = ((xoffset + j) * sin(angle) + (yoffset + i) * cos(angle));

		// 		Plot(tempx - xoffset + x, tempy - yoffset + y, col);
		// 	}
		// }
		float tempx;
        float tempy;
        for (float i = 0; i <= b_height; i += 0.1)
        {
            for (float j = 0; j <= b_width; j += 0.1)
            {
                tempx = x + j;
                tempy = y + i;

                Plot(tempx, tempy, col);
            }
        }
	}
	void Clip(int &x, int &y)
	{
		if (x < 0) x = 0;
		if (x >= s_width) x = s_width;
		if (y < 0) y = 0;
		if (y >= s_height) y = s_height;
	}

	void Fill(int x1, int y1, int x2, int y2, short c = blueF, short col = greenF)
	{
		Clip(x1, y1);
		Clip(x2, y2);
		for (int x = x1; x < x2; x++)
			for (int y = y1; y < y2; y++)
				Plot(x, y, col,c);
	}

	const void drawCircle(float xc, float yc, float r, short bordercol = whiteF, bool filled = 0, short innerCol = whiteF)
	{

		float x = -1;
		float y = r;
		if (filled)
		{
			for (float yn = -r; yn < r; yn += 0.1)
				for (float xn = -r; xn < r; xn += 0.1)
					if (xn * xn + yn * yn < r * r)
						Plot(xc + xn, yc + yn, innerCol);
		}

		Plot(x + xc, y + yc, bordercol);
		float pk = 3 - 2 * r;
		while (y > x)
		{

			if (pk < 0)
			{
				pk += 4 * x + 6;
				x += 1;
				std::vector<std::pair<float, float>> coords1{{x, y}, {y, x}, {y, -x}, {x, -y}, {-x, -y}, {-y, -x}, {-y, x}, {-x, y}};
				for (auto i : coords1)
					Plot(i.first + xc, i.second + yc, bordercol);
			}
			else
			{
				pk += 4 * (x - y) + 10;
				x = x + 1;
				y -= 1;
				std::vector<std::pair<float, float>> coords2{{x, y}, {y, x}, {y, -x}, {x, -y}, {-x, -y}, {-y, -x}, {-y, x}, {-x, y}};
				for (auto i : coords2)
					Plot(i.first + xc, i.second + yc, bordercol);
			}
		}
	}
	void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, float angle = 0, short col = whiteF)
	{
		float tempx, tempy, tempx_a, tempy_a;
		tempx = ((x1)*cos(angle) - (y1)*sin(angle));
		tempy = ((x1)*sin(angle) + (y1)*cos(angle));
		tempx_a = ((x2)*cos(angle) - (y2)*sin(angle));
		tempy_a = ((x2)*sin(angle) + (y2)*cos(angle));

		drawLine(tempx, tempy, tempx_a, tempy_a, col);
		tempx = ((x3)*cos(angle) - (y3)*sin(angle));
		tempy = ((x3)*sin(angle) + (y3)*cos(angle));

		drawLine(tempx_a, tempy_a, tempx, tempy, col);

		tempx_a = ((x1)*cos(angle) - (y1)*sin(angle));
		tempy_a = ((x1)*sin(angle) + (y1)*cos(angle));

		drawLine(tempx, tempy, tempx_a, tempy_a, col);
	}
};
