#include"./Plotter.h"

Plotter::Plotter(StateManager& stateManager,ConsoleHandler& console):stateManager(stateManager),console(console) {}

void Plotter::Plot(float x, float y, short col = whiteF, short c = 0x2588){
	stateManager.translateCoordinates(x,y);
	if (x > 1 && x < console.console_width - 1 && y > 1 && y < console.console_height - 1)
	{
		console.buffscreen[int(x) + console.console_width * int(y)].Char.UnicodeChar = c;
		console.buffscreen[int(x) + console.console_width * int(y)].Attributes = col;
	}
}