#include "Region.h"

Region::Region(Coordinate size)
	: Region(Coordinate(0, 0), Coordinate(size.X - 1, size.Y - 1))
{ }

Region::Region(Coordinate topLeft, Coordinate bottomRight)
	: topLeft(topLeft), bottomRight(validateBottomRight(bottomRight))
{ }

Region Region::operator+(Coordinate delta) const
{
	return Region(topLeft + delta, bottomRight + delta);
}

Region Region::operator-(Coordinate delta) const
{
	return Region(topLeft - delta, bottomRight - delta);
}

Coordinate Region::getTopLeft() const
{
	return topLeft;
}

Coordinate Region::getBottomRight() const
{
	return bottomRight;
}

Coordinate Region::getTopRight() const
{
	return Coordinate(bottomRight.X, topLeft.Y);
}

Coordinate Region::getBottomLeft() const
{
	return Coordinate(topLeft.X, bottomRight.Y);
}

Coordinate Region::getSize() const
{
	return Coordinate(getWidth(), getHeight());
}

int Region::getWidth() const
{
	return bottomRight.X - topLeft.X + 1;
}

int Region::getHeight() const
{
	return bottomRight.Y - topLeft.Y + 1;
}

int Region::getTop() const
{
	return topLeft.Y;
}

int Region::getLeft() const
{
	return topLeft.X;
}

int Region::getBottom() const
{
	return bottomRight.Y;
}

int Region::getRight() const
{
	return bottomRight.X;
}

std::string Region::toString() const
{
	return "[" + topLeft.toString() + " / " + bottomRight.toString() + "]";
}

Coordinate Region::validateBottomRight(Coordinate bottomRight)
{
	if (bottomRight.X < topLeft.X)
		bottomRight.X = topLeft.X;
	if (bottomRight.Y < topLeft.Y)
		bottomRight.Y = topLeft.Y;
	return bottomRight;
}
