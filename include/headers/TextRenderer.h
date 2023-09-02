#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H
#include <sstream>
#include <string>
#include "ConsoleHandler.h"
#include "StateManager.h"
using std::wstring;

class TextRenderer
{
private:
	ConsoleHandler& console;
	StateManager& stateManager;
public:
	TextRenderer(ConsoleHandler &console,StateManager& stateManager);
	void drawTextFromInt(float x, float y, wstring s, int b, short col);
	void Text(float x, float y, wstring a, short col);
};

#endif