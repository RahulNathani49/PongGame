#pragma once
#include "Coordinate.h"
using utility::Coordinate;

class Region
{
private:
	Coordinate topLeft;
	Coordinate bottomRight;

public:
	Region(Coordinate size);
	Region(Coordinate topLeft, Coordinate bottomRight);

	Region operator+(Coordinate delta) const;
	Region operator-(Coordinate delta) const;

	Coordinate getTopLeft() const;
	Coordinate getBottomRight() const;
	Coordinate getTopRight() const;
	Coordinate getBottomLeft() const;

	Coordinate getSize() const;
	int getWidth() const;
	int getHeight() const;

	int getTop() const;
	int getLeft() const;
	int getBottom() const;
	int getRight() const;

	std::string toString() const;

private:
	Coordinate validateBottomRight(Coordinate bottomRight);
};
