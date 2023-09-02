#include "Fazen.h"

Fazen::Fazen(int s_width,int s_height):console(s_width, s_height)
,stateManager(),plotter(stateManager,console),mouseHandler(console){}

