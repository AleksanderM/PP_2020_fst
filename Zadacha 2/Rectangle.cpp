#include "Rectangle.h"
Rectangle::Rectangle() {
	coords.lX = 0;
	coords.lY = 0;
	coords.rX = 0;
	coords.rY = 0;
	id = "";
	height = 0;
	width = 0;
}

Rectangle::Rectangle(std::string nId, int nLX, int nLY, int nHeight, int nWidth) 
{
	coords.lX = nLX;
	coords.lY = nLY;
	coords.rX = nLX + nWidth;
	coords.rY = nLY + nHeight;

	id = nId;
	height = nHeight;
	width = nWidth;
}

int Rectangle::overlap(Rectangle& other)
{
	int result = 1;

	std::cout << "first coords: " << coords.lX << "," << coords.lY << 
		", " << coords.rX << "," << coords.rY << "\n";
	

	std::cout << "2nd coords coords: " << other.coords.lX << "," << other.coords.lY <<
		", " << other.coords.rX << "," << other.coords.rY << "\n";

	if (!(coords.lX < other.coords.rX)) 
	{
		std::cout << "1" << "\n";
		return 0;
	}
	else if (!(coords.rX > other.coords.lX))
	{
		std::cout << "2" << "\n";
		return 0;
	}
	else if (!(coords.lY < other.coords.rY))
	{
		std::cout << "3" << "\n";
		return 0;
	}
	else if (!(coords.rY > other.coords.lY))
	{
		std::cout << "4" << "\n";
		return 0;
	}

	return 1;
}

std::string Rectangle::getId(void) 
{
	return id;
}

