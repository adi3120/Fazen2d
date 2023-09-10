#include "headers/Line.h"
#include "headers/Point.h"

Line::Line(float x1,float y1,float x2,float y2,short color,short character){
	this->x1=x1;
	this->x2=x2;
	this->y1=y1;
	this->y2=y2;
	this->color=color;
	this->character=character;
}

void Line::setX1(float x1){
	this->x1=x1;
}
void Line::setY1(float y1){
	this->y1=y1;
}
void Line::setX2(float x2){
	this->x2=x2;
}
void Line::setY2(float y2){
	this->y2=y2;
}
void Line::setColor(short color){
	this->color=color;
}
void Line::setCharacter(short character){
	this->character=character;
}
float Line::getX1(){
	return this->x1;
}
float Line::getY1(){
	return this->y1;
}
float Line::getX2(){
	return this->x2;
}
float Line::getY2(){
	return this->y2;
}
float Line::getColor(){
	return this->color;
}
float Line::getCharacter(){
	return this->character;
}
void Line::draw(){
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
		Point p(x,y,color,character);
		p.draw();
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
			Point p(x,y,color,character);
			p.draw();
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

		Point p(x,y,color,character);
		p.draw();

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
			Point p(x,y,color,character);
			p.draw();
		}
	}
}

void Line::translate(float dx,float dy){
	float nx1=this->x1+dx;
	float ny1=this->y1+dy;
	float nx2=this->x2+dy;
	float ny2=this->y2+dy;
	if((nx1>=0 && ny1>=0) && (nx2>=0 && ny2>=0)){
		if(nx1<ConsoleHandler::GetConsoleWidth() && nx2<ConsoleHandler::GetConsoleWidth()){
			if(ny1<ConsoleHandler::GetConsoleHeight() && ny1<ConsoleHandler::GetConsoleHeight()){
				this->x1=nx1;
				this->x2=nx2;
				this->y1=ny1;
				this->y2=ny2;
			}
		}
	}
}