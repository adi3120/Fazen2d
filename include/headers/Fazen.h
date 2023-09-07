#ifndef FAZEN_H
#define FAZEN_H
#include <windows.h>

#include "StateManager.h"
#include "ConsoleHandler.h"
#include "MathUtils.h"
#include "Colors.h"
#include "MouseHandler.h"
#include "KeyboardHandler.h"
#include "GraphicsRenderer.h"
#include "TimeManager.h"
#include "TextRenderer.h"
#include "Circle.h"
#include "Point.h"

class Fazen
{

public:
	ConsoleHandler console;
	GraphicsRenderer graphics;
	KeyboardHandler keyboardHandler;
	TimeManager timer;
	TextRenderer textRenderer;
	MouseHandler mouseHandler;
	Fazen(int s_width, int s_height);
};

#endif

