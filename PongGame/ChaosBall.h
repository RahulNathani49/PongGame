#pragma once
#include "Ball.h"
#include "Random.h"
class ChaosBall : public Ball
{

public:	
	char getSymbol();
	ChaosBall(Region map, Coordinate position);
	void BounceHorizontally() override; 
	void BounceVertically() override;
	
};

