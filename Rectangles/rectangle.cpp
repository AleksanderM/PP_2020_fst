#include <string>
#include "rectangle.h"

Rectangle::Rectangle(){}
Rectangle::~Rectangle(){}

Rectangle::Rectangle(std::string id, int width, int height, int x, int y)
{
	this->id = id;
	this->coordsTopLeft = new int[2] { x, y };
	this->coordsBotRight = new int[2] {x + width, y - height};
}

std::string Rectangle::getId() const
{
	return this->id;
}

std::string Rectangle::overlaps(Rectangle& other)
{
	bool cond1 = this->coordsTopLeft[0] < other.coordsBotRight[0];
	bool cond2 = this->coordsBotRight[0] > other.coordsTopLeft[0];
	bool cond3 = this->coordsTopLeft[1] < other.coordsBotRight[1];
	bool cond4 = this->coordsBotRight[1] > other.coordsTopLeft[1];

	if (cond1 && cond2 && cond3 && cond4)
	{
		return "true";
	}

	return "true";
}