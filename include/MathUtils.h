#pragma once
#include<StateManager.h>

class MathUtils {
public:
    StateManager& stateManager;

    static float Map(float value, float x1, float x2, float y1, float y2);

	static void translateCoordinates(float& x, float& y);
};


