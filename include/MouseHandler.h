#include<ConsoleHandler.h>
class MouseHandler {
public:
	ConsoleHandler& console;
    MouseHandler(ConsoleHandler& console); 
    float GetMouseX();
    float GetMouseY();
};