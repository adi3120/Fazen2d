#include"headers/GraphicsRenderer.h"
#include "headers/Colors.h"
GraphicsRenderer::GraphicsRenderer(ConsoleHandler& console, StateManager& stateManager):console(console),stateManager(stateManager){}

void GraphicsRenderer::Plot(float x, float y, short col = whiteF, short c = 0x2588){
	stateManager.translateCoordinates(x,y);
	if (x > 1 && x < console.GetConsoleWidth() - 1 && y > 1 && y < console.GetConsoleHeight() - 1)
	{
		console.GetBuffScreen()[int(x) + console.GetConsoleWidth() * int(y)].Char.UnicodeChar = c;
		console.GetBuffScreen()[int(x) + console.GetConsoleWidth() * int(y)].Attributes = col;
	}
}

void GraphicsRenderer::display(){
	WriteConsoleOutputW(console.GetOutHandle(), console.GetBuffScreen(), console.GetBufferSize(), console.GetCharacterPos(), console.GetRectWin());
}

void GraphicsRenderer::background(short col=0){
	for (int i = 0; i < console.GetConsoleHeight() * console.GetConsoleWidth(); i++)
	{
		console.GetBuffScreen()[i].Char.UnicodeChar = ' ';
		console.GetBuffScreen()[i].Attributes = col;
	}
}

void GraphicsRenderer::drawLine(float x2, float y2, float x1, float y1, short col = whiteF, short c = 0x2588){
	float x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
	dx = x2 - x1;
	dy = y2 - y1;
	dx1 = std::abs(dx);
	dy1 = std::abs(dy);
	px = 2 * dy1 - dx1;
	py = 2 * dx1 - dy1;
	if (dy1 <= dx1)
	{
		if (dx >= 0){
			x = x1;
			y = y1;
			xe = x2;
		}
		else{
			x = x2;
			y = y2;
			xe = x1;
		}
		Plot(x, y, col, c);
		for (i = 0; x < xe; i++){
			x = x + 1;
			if (px < 0)
				px = px + 2 * dy1;
			else{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
					y = y + 1;
				else
					y = y - 1;
				px = px + 2 * (dy1 - dx1);
			}
			Plot(x, y, col, c);
		}
	}
	else{
		if (dy >= 0){
			x = x1;
			y = y1;
			ye = y2;
		}
		else{
			x = x2;
			y = y2;
			ye = y1;
		}
		Plot(x, y, col, c);
		for (i = 0; y < ye; i++){
			y = y + 1;
			if (py <= 0)
				py = py + 2 * dx1;
			else{
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

void GraphicsRenderer::drawRectangle(float x, float y, int b_width, int b_height, float angle = 0, short col = whiteF)
{
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

void GraphicsRenderer::drawCircle(float xc, float yc, float r, short innerCol = whiteF)
{
	float bx=xc-r;
	float by=yc-r;

	float ex=xc+r;
	float ey=yc+r;

	for(float yn=by;yn<=ey;yn++){
		for(float xn=bx;xn<=ex+1;xn++){
			float dx=xc-xn;
			float dy=yc-yn;
			if((dx*dx) + (dy*dy) <= r*r){
				Plot(xn, yn, innerCol);
			}
		}
	}

}