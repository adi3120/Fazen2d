#ifndef BOX_H
#define BOX_H

#include "Shape.h"

class Box:public Shape{
private:
	float x;
	float y;
	float width;
	float height;
	short color;
	short character;
public:
	explicit Box(float x,float y,float width,float height,short color,short character=0x2588);
	void setPosX(float x);
	void setPosY(float y);
	void setWidth(float width);
	void setHeight(float height);
	void setColor(short color);
	void setCharacter(short character);
	float getPosX();
	float getPosY();
	float getColor();
	float getCharacter();
	float getWidth();
	float getHeight();
	void draw() override;
	void translate(float dx,float dy) override;
};
#endif