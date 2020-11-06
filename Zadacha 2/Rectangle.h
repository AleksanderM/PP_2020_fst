#pragma once
#include <iostream>

struct Coordinates {
	int lX, lY;
	int rX, rY;
	
	Coordinates() {
		rX = 0;
		rY = 0;
		lX = 0;
		lY = 0;
	}
};

class Rectangle {

	std::string id;
	int			height;
	int			width;
	Coordinates coords;

public:

	Rectangle(const Rectangle&) = default;

	Rectangle();
	Rectangle(std::string, int, int, int, int);

	std::string getId(void);

	int overlap(Rectangle&);

};
