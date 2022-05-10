#pragma once
#include "Coordinate.h"
#include "Region.h"
#include "Paddle.h"
using utility::Coordinate;
class Ball
{
private:
	Region map;
	Coordinate position;
	Coordinate velocity;
public:
	Ball(Region map, Coordinate position);
	Ball(Region map, Coordinate position,Coordinate velocity);
	Coordinate getPosition();
	Coordinate getVelocity();
	Coordinate getTargetPosition();
	void setPosition(Coordinate position);
	virtual void BounceHorizontally();
	virtual void BounceVertically();
	void move();
	virtual char getSymbol();
private:
	
};

