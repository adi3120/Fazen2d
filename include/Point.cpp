#include "headers/Point.h"
#include "headers/ConsoleHandler.h"

Point::Point(float x, float y, short color, short character)
        :x(x), y(y), color(color), character(character) {}


void Point::setPosX(float x){
	this->x=x;
}

void Point::setPosY(float y){
	this->y=y;
}

void Point::setColor(short color){
	this->color=color;
}

void Point::setCharacter(short character){
	this->character=character;
}

float Point::getPosX(){
	return this->x;
}
float Point::getPosY(){
	return this->y;
}
float Point::getColor(){
	return this->color;
}
float Point::getCharacter(){
	return this->character;
}

void Point::draw(){
	// stateManager.translateCoordinates(this->x,this->y);
	if (x > 1 && x < ConsoleHandler::GetConsoleWidth() - 1 && y > 1 && y < ConsoleHandler::GetConsoleHeight() - 1)
	{
		ConsoleHandler::GetBuffScreen()[int(x) + ConsoleHandler::GetConsoleWidth() * int(y)].Char.UnicodeChar = character;
		ConsoleHandler::GetBuffScreen()[int(x) + ConsoleHandler::GetConsoleWidth() * int(y)].Attributes = color;
	}
}