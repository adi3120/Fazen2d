#include "headers/Text.h"

Text::Text(float x,float y,wstring s,short color){
	this->x=x;
	this->y=y;
	this->value=s;
	this->color=color;
}
Text::Text(float x,float y,int b,short color){
	std::wostringstream ws;
	ws << b;
	std::wstring a = (ws.str());

	this->x=x;
	this->y=y;
	this->value=a;
	this->color=color;
}

void Text::setPosX(float x){
	this->x=x;
}
void Text::setPosY(float y){
	this->y=y;
}
void Text::setValue(wstring s){
	this->value=s;
}
void Text::setValue(int b){
	std::wostringstream ws;
	ws << b;
	std::wstring a = (ws.str());
	this->value=a;
}
void Text::setColor(short color){
	this->color=color;
}

float Text::getPosX(){
	return this->x;
}
float Text::getPosY(){
	return this->y;
}
wstring Text::getValue(){
	return this->value;
}
short Text::getColor(){
	return this->color;
}
void Text::draw(){

	for (size_t i = 0; i < this->value.size(); i++)
	{
		ConsoleHandler::GetBuffScreen()[(int)(x + i + ConsoleHandler::GetConsoleWidth() * y)].Char.UnicodeChar = this->value[i];
		ConsoleHandler::GetBuffScreen()[(int)(x + i + ConsoleHandler::GetFontWidth() * y)].Attributes = color;
	}
}