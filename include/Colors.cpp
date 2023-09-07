#include "headers/Colors.h"

Color::Color(short fgColor,short bgColor){
	this->fgColor=fgColor;
	this->bgColor=bgColor;
	this->value=fgColor|bgColor;
}
void Color::setFgColor(short fgColor){
	this->fgColor=fgColor;
}
void Color::setBgColor(short bgColor){
	this->bgColor=bgColor;
}
void Color::setValue(short value){
	this->value=value;
}
short Color::getFgColor(){
	return this->fgColor;
}
short Color::getBgColor(){
	return this->bgColor;
}
short Color::getValue(){
	return this->value;
}