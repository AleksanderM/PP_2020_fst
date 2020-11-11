/*
 * Rectangle.h
 *
 *  Created on: 6.11.2020 ã.
 *      Author: ivan
 */

#include <string>
using namespace std;


class Rectangle{
public:
	string getID();
	void setID(string x);

	int getHight();
	void setHight(int x);

	int getWidth();
	void setWidth(int x);

	int getCordX();
	void setCordX(int x);

	int getCordY();
	void setCordY(int x);

	int getLeft();
	int getRight();
	int getBottom();
	int getTop();


private:
	string ID;
	int hight,width,cordX,cordY;
};
