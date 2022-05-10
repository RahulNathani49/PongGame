#include "Paddle.h"

Paddle::Paddle(Region map, Coordinate top, int height)
	: map(map),
	height(validateHeight(height)),
	top(validateTop(top))
{ }

Region Paddle::getMap()
{
	return map;
}

Region Paddle::getRegion()
{
	return Region(top, getBottom());
}

int Paddle::getHeight()
{
	return height;
}

Coordinate Paddle::getTop()
{
	return top;
}

Coordinate Paddle::getBottom()
{
	return Coordinate(top.X, top.Y + height - 1);
}

void Paddle::move(int offset)
{
	setTop(Coordinate(top.X, top.Y + offset));
}
void Paddle::moveHorizontal(int offset)
{
	setTop(Coordinate(top.X+offset,top.Y));
}


void Paddle::setTop(Coordinate top)
{
	int mapTop = map.getTop();
	int mapBottom = map.getBottom();
	int mapLeft = map.getLeft();
	int mapRight = map.getRight();

	if (top.Y < mapTop)
		top.Y = mapTop;
	else if (top.Y + height - 1 > mapBottom)
		top.Y = mapBottom - height + 1;

	if (top.X < mapLeft)
		top.X = mapLeft;
	else if (top.X + height - 1 > mapRight)
		top.X = mapRight - height + 1;

	this->top = top;
}
void Paddle::setHorizontal() {
	setTop(Coordinate(top.X+height, top.X));
}
int Paddle::validateHeight(int height)
{
	int min = 1;
	int max = map.getHeight() - 1;

	if (height < min)
		return min;
	if (height > max)
		return max;
	return height;
}

Coordinate Paddle::validateTop(Coordinate top)
{
	Coordinate min = map.getTopLeft();
	Coordinate max = Coordinate(map.getRight(), map.getBottom() - height);
	return Coordinate::clamp(top, min, max);
}
