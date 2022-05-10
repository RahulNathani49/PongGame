#include "ChaosBall.h"

char ChaosBall::getSymbol()
{
	return '#';
}


ChaosBall::ChaosBall(Region map, Coordinate position):Ball(map,position)
{

}


void ChaosBall::BounceHorizontally()
{
	if (utility::Random::getInteger(0, 1)) {
		Ball::BounceHorizontally();
	}
	else {
		Ball::BounceVertically();
		Ball::BounceHorizontally();
	}
}


void ChaosBall::BounceVertically()
{
	if (utility::Random::getInteger(0, 1)) {
		Ball::BounceVertically();
	}
	else {
		Ball::BounceVertically();
		Ball::BounceHorizontally();
	}
}



