#ifndef FAZEN_H
#define FAZEN_H
#include <windows.h>

#include "StateManager.h"
#include "ConsoleHandler.h"
#include "MathUtils.h"
#include "Plotter.h"
#include "Colors.h"
#include "MouseHandler.h"

class Fazen
{
public:
	ConsoleHandler console;
	StateManager stateManager;
	Plotter plotter;
	MouseHandler mouseHandler;
	Fazen(int s_width, int s_height);
};

#endif