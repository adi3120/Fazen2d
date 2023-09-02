#ifndef PLOTTER_H
#define PLOTTER_H

#include"./StateManager.h"
#include"./Colors.h"
#include"./ConsoleHandler.h"

class Plotter {
private:
    CHAR_INFO* buffscreen;
    StateManager& stateManager;
	ConsoleHandler& console;

public:
    Plotter(StateManager& stateManager, ConsoleHandler& console);

    void Plot(float x, float y, short col, short c);
};

#endif