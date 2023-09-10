#include "headers/Box.h"
#include "headers/Point.h"

Box::Box(float x,float y,float width,float height,short color,short character){
	this->x=x;
	this->y=y;
	this->width=width;
	this->height=height;
	this->color=color;
	this->character=character;
}

void Box::setPosX(float x){
	this->x=x;
}

void Box::setPosY(float y){
	this->y=y;
}

void Box::setColor(short color){
	this->color=color;
}

void Box::setWidth(float width){
	this->width=width;
}

void Box::setHeight(float height){
	this->height=height;
}

void Box::setCharacter(short character){
	this->character=character;
}

float Box::getPosX(){
	return this->x;
}
float Box::getPosY(){
	return this->y;
}
float Box::getColor(){
	return this->color;
}
float Box::getCharacter(){
	return this->character;
}
float Box::getWidth(){
	return this->width;
}

float Box::getHeight(){
	return this->height;
}

void Box::draw(){
	float tempx;
	float tempy;
	for (float i = 0; i <= this->height; i += 0.1)
	{
		for (float j = 0; j <= this->width; j += 0.1)
		{
			tempx = x + j;
			tempy = y + i;

			Point p(tempx,tempy,color,character);
			p.draw();
		}
	}
}

void Box::translate(float dx,float dy){
	float nx=this->x+dx;
	float ny=this->y+dy;
	if((nx>=0 && ny>=0) && ((nx+this->width)<ConsoleHandler::GetConsoleWidth() && (ny+this->height)<ConsoleHandler::GetConsoleHeight())){
		this->x=nx;
		this->y=ny;
	}
}