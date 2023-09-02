#include <string>
#include <windows.h>
#include <sstream>
#include <vector>
#include <chrono>
#include <cmath>
#include<ConsoleHandler.h>
#include<StateManager.h>
using std::wstring;
const float pi = 3.141592653589793238;
class Fazen
{
private:
	ConsoleHandler console;	
public:
	Fazen(CHAR_INFO* buffscreen, int fontH, int fontW);
	
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
