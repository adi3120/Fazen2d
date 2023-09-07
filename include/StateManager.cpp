#include "headers/StateManager.h"

float StateManager::center_x=0;
float StateManager::center_y=0;
float StateManager::tempCenterx=0;
float StateManager::tempCentery=0;

void StateManager::saveState() {
	tempCenterx = center_x;
	tempCentery = center_y;
}

void StateManager::restoreState() {
	center_x = tempCenterx;
	center_y = tempCentery;
}

void StateManager::setCenter(float x, float y) {
	center_x = x;
	center_y = y;
}

float StateManager::getCenterX(){
	return center_x;
}

float StateManager::getCenterY(){
	return center_y;
}

void StateManager::translateCoordinates(float& x, float& y) {
        x += getCenterX();
        y += getCenterY();
}