#include "Ball.h"
Ball::Ball(Region map, Coordinate position) :Ball(map, position, Coordinate(1, 1)) {
	int minLeft = map.getLeft();
	int maxRight = map.getRight();
	int maxBottom = map.getBottom();
	int minTop = map.getTop();
	if (position.Y > maxBottom)
	{
		position.Y = maxBottom;
	}
	else if (position.Y < minTop)
	{
		position.Y = minTop;
	}
	this->position.Y = position.Y;

	if (position.X < minLeft) {
		position.X = minLeft;
	}
	else if (position.X > maxRight) {
		position.X = maxRight;
	}
	this->position.X = position.X;
}
Ball::Ball(Region map, Coordinate position, Coordinate velocity)
	:map(map),position(position),velocity(velocity)
{
	
}
Coordinate Ball::getPosition()
{
	return position;
}
Coordinate Ball::getVelocity()
{
	return velocity;
}
Coordinate Ball::getTargetPosition()
{
	if (position.Y > map.getBottom()-1) {
		position.Y = map.getBottom()-1;
	}
	else if (position.Y < map.getTop()+1) {
		position.Y = map.getTop()+1;
	}
	if (position.X > map.getRight() - 1) {
		position.X = map.getRight() - 1;
	}
	else if (position.X < map.getLeft() + 1) {
		position.X = map.getLeft() + 1;
	}

	return position + velocity;
}
void Ball::setPosition(Coordinate position)
{

	if (position.Y == map.getBottom() || position.Y == map.getTop())
		BounceVertically();

	if (position.X == map.getRight() || position.X==map.getLeft())
		BounceHorizontally();
	
	this->position = position;
	
}
void Ball::move() {
	setPosition(getTargetPosition());
	
}
char Ball::getSymbol()
{
	return 'O';
}
 void Ball::BounceHorizontally()
{
	if (velocity.X > 0)
		velocity.X = -1;
	else
		velocity.X = 1;
}
 void Ball::BounceVertically()
{
	if (velocity.Y > 0 ) 
		velocity.Y = -1;
	else
		velocity.Y = 1;

}

