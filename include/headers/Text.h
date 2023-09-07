#ifndef TEXT_H
#define TEXT_H
#include "Shape.h"
#include <sstream>
#include <string>
using std::wstring;

class Text:public Shape{
private:
	float x;
	float y;
	wstring value;
	short color;

public:
	Text(float x,float y,wstring s,short color);
	Text(float x,float y,int b,short color);

	void setPosX(float x);
	void setPosY(float y);
	void setValue(wstring s);
	void setValue(int b);
	void setColor(short color);

	float getPosX();
	float getPosY();
	wstring getValue();
	short getColor();

	void draw();
};

#endif