class StateManager {
private:
    float center_x;
    float center_y;
    float tempCenterx;
    float tempCentery;

public:
	void saveState();
    void restoreState();
    void setCenter(float x, float y);
    float getCenterX();
    float getCenterY();
};