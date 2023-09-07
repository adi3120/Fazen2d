#include "headers/GraphicsRenderer.h"
#include "headers/Colors.h"
#include "headers/ConsoleHandler.h"

void GraphicsRenderer::display(){
	WriteConsoleOutputW(
		ConsoleHandler::GetOutHandle(), 
		ConsoleHandler::GetBuffScreen(), 
		ConsoleHandler::GetBufferSize(), 
		ConsoleHandler::GetCharacterPos(), 
		ConsoleHandler::GetRectWin()
	);
}

void GraphicsRenderer::background(short col=0){
	for (int i = 0; i < ConsoleHandler::GetConsoleHeight() * ConsoleHandler::GetConsoleWidth(); i++)
	{
		ConsoleHandler::GetBuffScreen()[i].Char.UnicodeChar = ' ';
		ConsoleHandler::GetBuffScreen()[i].Attributes = col;
	}
}
void GraphicsRenderer::drawShape(Shape& s){
	s.draw();
}