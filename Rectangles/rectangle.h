#ifndef RECTANGLE
#define RECTANGLE

#include<string>

class Rectangle
{
public:
	Rectangle();
	Rectangle(std::string id, int width, int height, int x, int y);
	~Rectangle();
	std::string overlaps(Rectangle& other);
	std::string getId() const;

private:
	std::string id;
	int* coordsTopLeft;
	int* coordsBotRight;
};

#endif // !RECTANGLE

