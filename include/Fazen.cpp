#include "headers/Fazen.h"

Fazen::Fazen(int s_width, int s_height) : 
	console(s_width, s_height), 
	stateManager(), 
	mouseHandler(console), 
	graphics(console, stateManager),
	keyboardHandler(keyboardHandler),
	timer(timer) 
	{}
