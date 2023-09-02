#include "headers/MathUtils.h"

MathUtils::MathUtils(StateManager& stateManager): stateManager(stateManager){}

float MathUtils::Map(float value, float x1, float x2, float y1, float y2) {
    float m = (y2 - y1) / (x2 - x1);
    float b = y1 - m * x1;
    value = (value - b) / m;
    return value;
}
