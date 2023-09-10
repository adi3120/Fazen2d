#include "headers/Circle.h"
#include "headers/Point.h"

Circle::Circle(float xc,float yc,float radius,short color,short character): xc(xc),yc(yc),radius(radius),color(color),character(character){}


void Circle::setRadius(float radius){
	this->radius=radius;
}

void Circle::setCenterX(float xc){
	this->xc=xc;
}

void Circle::setCenterY(float yc){
	this->yc=yc;
}

void Circle::setColor(short color){
	this->color=color;
}

void Circle::setCharacter(short character){
	this->character=character;
}

float Circle::getRadius(){
	return this->radius;
}
float Circle::getCenterX(){
	return this->xc;
}
float Circle::getCenterY(){
	return this->yc;
}
float Circle::getColor(){
	return this->color;
}
float Circle::getCharacter(){
	return this->character;
}

void Circle::draw() {
	float bx=this->xc-this->radius;
	float by=this->yc-this->radius;

	float ex=this->xc+this->radius;
	float ey=this->yc+this->radius;

	for(float yn=by;yn<=ey;yn++){
		for(float xn=bx;xn<=ex+1;xn++){
			float dx=this->xc-xn;
			float dy=this->yc-yn;
			if((dx*dx) + (dy*dy) <= this->radius*this->radius){
				Point p(xn,yn,color,character);
				p.draw();
			}
		}
	}
}

void Circle::translate(float dx,float dy){
	float nx=this->xc+dx;
	float ny=this->yc+dy;
	if((nx>=this->radius && ny>=this->radius) && ((nx+this->radius)<ConsoleHandler::GetConsoleWidth() && (ny+this->radius)<ConsoleHandler::GetConsoleHeight())){
		this->xc=nx;
		this->yc=ny;
	}
}