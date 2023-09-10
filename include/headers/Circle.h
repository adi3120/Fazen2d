#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle:public Shape{
	private:
		float radius;
		float xc;
		float yc;
		short color;
		short character;
	public:
		explicit Circle(float xc,float yc,float radius,short color,short character=0x2588);
		void setRadius(float radius);
		void setCenterX(float xc);
		void setCenterY(float yc);
		void setColor(short color);
		void setCharacter(short character);
		float getRadius();
		float getCenterX();
		float getCenterY();
		float getColor();
		float getCharacter();
		void draw() override;
		void translate(float dx,float dy) override;
};

#endif
