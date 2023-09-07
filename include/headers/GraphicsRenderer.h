#ifndef GRAPHICSRENDERER_H
#define GRAPHICSRENDERER_H
#include "Shape.h"
class GraphicsRenderer{
	public:
		void display();
		void background(short col);
		void draw(Shape& s);
};

#endif