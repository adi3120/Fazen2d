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

class Fazen
{
public:
	ConsoleHandler console;
	StateManager stateManager;
	MouseHandler mouseHandler;
	GraphicsRenderer graphics;
	KeyboardHandler keyboardHandler;
	TimeManager timer;
	Fazen(int s_width, int s_height);
};

#endif