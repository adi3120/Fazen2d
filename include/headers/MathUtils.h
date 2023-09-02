#ifndef MATHUTILS_H
#define MATHUTILS_H

#include"StateManager.h"

class MathUtils {
public:
    StateManager& stateManager;
	MathUtils(StateManager& stateManager);
	static constexpr double pi = 3.141592653589793238;

    static float Map(float value, float x1, float x2, float y1, float y2);

	static void translateCoordinates(float& x, float& y);
};


#endif

