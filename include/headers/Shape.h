#ifndef SHAPE_H
#define SHAPE_H
#include "StateManager.h"
#include "ConsoleHandler.h"

class Shape{
	public:
		virtual void draw() = 0;
		virtual ~Shape()=default;
};

#endif