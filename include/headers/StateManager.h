#ifndef STATEMANAGER_H
#define STATEMANAGER_H

class StateManager {
private:
	static float center_x;
    static float center_y;
    static float tempCenterx;
    static float tempCentery;

public:
	static void saveState();
    static void restoreState();
    static void setCenter(float x, float y);
    static float getCenterX();
    static float getCenterY();
	static void translateCoordinates(float& x, float& y);
};

#endif