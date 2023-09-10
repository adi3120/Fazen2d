#ifndef POINT_H
#define POINT_H
#include "Shape.h"
class Point:public Shape{
	private:
		float x;
		float y;
		short color;
		short character;
	public:
		explicit Point(float x,float y,short color,short character=0x2588);
		void setPosX(float x);
		void setPosY(float y);
		void setColor(short color);
		void setCharacter(short character);
		float getPosX();
		float getPosY();
		float getColor();
		float getCharacter();
		void draw() override;
		void translate(float dx,float dy) override;
};

#endif
