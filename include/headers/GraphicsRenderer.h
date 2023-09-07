#ifndef GRAPHICSRENDERER_H
#define GRAPHICSRENDERER_H
#include "StateManager.h"
#include "Shape.h"
class GraphicsRenderer{
	public:
		void display();
		void background(short col);
		void drawShape(Shape& s);
};

#endif