#pragma once
#include "Coordinate.h"
#include "Region.h"
using utility::Coordinate;

class Paddle
{
private:
	Region map;
	int height;
	Coordinate top;

public:
	Paddle(Region map, Coordinate top, int height);

	Region getMap();
	Region getRegion();
	int getHeight();
	Coordinate getTop();
	Coordinate getBottom();

	void move(int offset);
	void moveHorizontal(int offset);
	void setHorizontal();
	
private:
	void setTop(Coordinate top);
	int validateHeight(int height);
	Coordinate validateTop(Coordinate top);
};

