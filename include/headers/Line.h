#ifndef LINE_H
#define LINE_H
#include "Shape.h"

class Line:public Shape{
private:
	float x1;
	float y1;
	float x2;
	float y2;
	short color;
	short character;
public:
	Line(float x1,float y1,float x2,float y2,short color,short character=0x2588);
	void setX1(float x1);
	void setY1(float x1);
	void setX2(float x1);
	void setY2(float x1);
	void setColor(short color);
	void setCharacter(short character);
	float getX1();
	float getY1();
	float getX2();
	float getY2();
	float getColor();
	float getCharacter();
	void draw() override;
	void translate(float dx,float dy) override;
};

#endif