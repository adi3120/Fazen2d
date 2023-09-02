#include "headers/TextRenderer.h"


TextRenderer::TextRenderer(ConsoleHandler &console,StateManager& stateManager):
	console(console),
	stateManager(stateManager)
	{}

void TextRenderer::drawTextFromInt(float x, float y, wstring s, int b, short col){
	stateManager.translateCoordinates(x,y);
	std::wostringstream ws;
	ws << b;

	std::wstring a = s + (ws.str());

	for (size_t i = 0; i < a.size(); i++)
	{
		console.GetBuffScreen()[(int)(x + i + console.GetConsoleWidth() * y)].Char.UnicodeChar = a[i];
		console.GetBuffScreen()[(int)(x + i + console.GetFontWidth() * y)].Attributes = col;
	}
}

void TextRenderer::Text(float x, float y, wstring a, short col){
	stateManager.translateCoordinates(x,y);

	for (size_t i = 0; i < a.size(); i++)
	{
		console.GetBuffScreen()[(int)(x + i + console.GetConsoleWidth() * y)].Char.UnicodeChar = a[i];
		console.GetBuffScreen()[(int)(x + i + console.GetConsoleWidth() * y)].Attributes = col;
	}
}