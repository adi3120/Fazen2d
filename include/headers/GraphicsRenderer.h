#ifndef GRAPHICSRENDERER_H
#define GRAPHICSRENDERER_H
#include "ConsoleHandler.h"
#include "StateManager.h"
class GraphicsRenderer{
	private:
		ConsoleHandler& console;
		StateManager& stateManager;
	public:
		GraphicsRenderer(ConsoleHandler& console,StateManager& stateManager);
		void display();
		void background(short col);
		void Plot(float x, float y, short col, short c);
		void drawLine(float x2, float y2, float x1, float y1, short col, short c);
		void drawRectangle(float x, float y, int b_width, int b_height, float angle, short col);
		void drawCircle(float xc, float yc, float r, short innerCol);
};

#endif