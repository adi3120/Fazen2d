#include<windows.h>
#include<StateManager.h>
#include<Colors.h>

class Plotter {
private:
    CHAR_INFO* buffscreen;
    StateManager& stateManager;

public:
    Plotter(CHAR_INFO* buffscreen, StateManager& stateManager)
        : buffscreen(buffscreen), stateManager(stateManager) {}

    void Plot(float x, float y, short col = whiteF, short c = 0x2588);
};